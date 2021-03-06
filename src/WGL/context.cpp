/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/logger.h"
#include "Common/macros.h"
#include "GDI32/globals.h"
#include "Khronos/GL/glcorearb.h"
#include "Khronos/GL/wglext.h"
#include "OpenGL/backend/vk_backend.h"
#include "WGL/context.h"
#include "WGL/globals.h"

std::unordered_map<HDC, WGL::Context*> g_context_map;
std::mutex                             g_context_map_mutex;

WGL::Context* WGL::get_wgl_context_for_hdc(HDC in_hdc)
{
    WGL::Context* result_ptr = nullptr;

    {
        std::lock_guard<std::mutex> lock                (g_context_map_mutex);
        auto                        context_map_iterator(g_context_map.find(in_hdc) );

        vkgl_assert(context_map_iterator != g_context_map.end() );
        if (context_map_iterator != g_context_map.end() )
        {
            result_ptr = context_map_iterator->second;
        }
    }

    return result_ptr;
}

WGL::Context::Context()
    :m_current_hdc                  (nullptr),
     m_is_debug_context             (false),
     m_is_forward_compatible_context(false),
     m_n_layer_plane                (0),
     m_major_version                (1),
     m_minor_version                (0)
{
    memset(&m_pixel_format_reqs,
           0,
           sizeof(m_pixel_format_reqs) );
}

WGL::Context::~Context()
{
    m_gl_context_ptr.reset();

    set_current_hdc(nullptr);

    m_vk_backend_ptr.reset();
}

WGL::Context* WGL::Context::create(const HDC&     in_hdc,
                                   const Context* in_opt_share_context_ptr,
                                   const int*     in_attribute_list_ptr)
{
    WGL::Context* result_ptr;

    result_ptr = new WGL::Context();

    if (result_ptr != nullptr)
    {
        if (!result_ptr->init(in_hdc,
                              in_opt_share_context_ptr,
                              in_attribute_list_ptr) )
        {
            /* TODO: An error code corresponding to the reason behind the failure should be exposed via Kernel32.dll::GetLastError() */
            vkgl_assert_fail();

            delete result_ptr;
            result_ptr = nullptr;
        }
    }

    return result_ptr;
}

void WGL::Context::get_rendering_surface_size(uint32_t* out_width_ptr,
                                              uint32_t* out_height_ptr) const
{
    vkgl_assert(m_current_hdc  != nullptr);
    vkgl_assert(out_height_ptr != nullptr);
    vkgl_assert(out_width_ptr  != nullptr);

    HWND hwnd = ::WindowFromDC(m_current_hdc);
    RECT rect = {0};

    vkgl_assert(hwnd != nullptr);

    ::GetClientRect(hwnd,
                   &rect);

    *out_width_ptr  = rect.right - rect.left;
    *out_height_ptr = rect.bottom - rect.top;
}

bool WGL::Context::init(const HDC&     in_hdc,
                        const Context* in_share_context_ptr,
                        const int*     in_attribute_list_ptr)
{
    const int* attribute_list_traveller_ptr = in_attribute_list_ptr;
    uint32_t   pixel_format_index           = UINT32_MAX;
    bool       result                       = true;

    pixel_format_index = reinterpret_cast<GDI32::PFNGETPIXELFORMATPROC>(GDI32::g_cached_get_pixel_format_func_ptr)(in_hdc);
    if (pixel_format_index == 0)
    {
        VKGL_LOG(VKGL::LogLevel::Error,
                 "Could not retrieve pixel format index for the specified HDC.");

        vkgl_assert_fail();

        result = false;
        goto end;
    }

    {
        PIXELFORMATDESCRIPTOR pixel_format_descriptor;

        if (reinterpret_cast<GDI32::PFNDESCRIBEPIXELFORMATPROC>(GDI32::g_cached_describe_pixel_format_func_ptr)(in_hdc,
                                                                                                                pixel_format_index,
                                                                                                                sizeof(PIXELFORMATDESCRIPTOR),
                                                                                                               &pixel_format_descriptor) == 0)
        {
            VKGL_LOG(VKGL::LogLevel::Error,
                     "Failed to retrieve pixel format properties for the specified HDC.");

            vkgl_assert_fail();

            result = false;
            goto end;
        }

        {
            if (pixel_format_descriptor.cAccumBits != 0)
            {
                VKGL_LOG(VKGL::LogLevel::Warning,
                         "Accumulation bits were incorrectly requested; accumulation is not supported by VKGL. Request will be ignored.");
            }

            m_pixel_format_reqs.n_alpha_bits       = pixel_format_descriptor.cAlphaBits;
            m_pixel_format_reqs.n_alpha_shift_bits = pixel_format_descriptor.cAlphaShift;
            m_pixel_format_reqs.n_blue_bits        = pixel_format_descriptor.cBlueBits;
            m_pixel_format_reqs.n_blue_shift_bits  = pixel_format_descriptor.cBlueShift;
            m_pixel_format_reqs.n_depth_bits       = pixel_format_descriptor.cDepthBits;
            m_pixel_format_reqs.n_green_bits       = pixel_format_descriptor.cGreenBits;
            m_pixel_format_reqs.n_green_shift_bits = pixel_format_descriptor.cGreenShift;
            m_pixel_format_reqs.n_red_bits         = pixel_format_descriptor.cRedBits;
            m_pixel_format_reqs.n_red_shift_bits   = pixel_format_descriptor.cRedShift;
            m_pixel_format_reqs.n_stencil_bits     = pixel_format_descriptor.cStencilBits;
        }
    }

    if (attribute_list_traveller_ptr == nullptr)
    {
        /* Most likely a trampoline context. Assume success. */
        goto end;
    }

    while ( attribute_list_traveller_ptr != nullptr &&
           *attribute_list_traveller_ptr != 0)
    {
        const auto attribute_name  = * attribute_list_traveller_ptr;
        const auto attribute_value = *(attribute_list_traveller_ptr + 1);

        switch (attribute_name)
        {
            case WGL_CONTEXT_LAYER_PLANE_ARB:
            {
                m_n_layer_plane = attribute_value;

                break;
            }

            case WGL_CONTEXT_MAJOR_VERSION_ARB:
            {
                m_major_version = attribute_value;

                break;
            }

            case WGL_CONTEXT_MINOR_VERSION_ARB:
            {
                m_minor_version = attribute_value;

                break;
            }

            case WGL_CONTEXT_FLAGS_ARB:
            {
                m_is_debug_context              |= (attribute_value & WGL_CONTEXT_DEBUG_BIT_ARB)              != 0;
                m_is_forward_compatible_context |= (attribute_value & WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB) != 0;

                break;
            }

            case WGL_CONTEXT_PROFILE_MASK_ARB:
            {
                if (attribute_value != WGL_CONTEXT_CORE_PROFILE_BIT_ARB)
                {
                    VKGL_LOG(VKGL::LogLevel::Error,
                             "VKGL does not support OpenGL profiles other than core.");

                    vkgl_assert_fail();

                    result = false;
                    goto end;
                }

                break;
            }

            default:
            {
                VKGL_LOG(VKGL::LogLevel::Error,
                         "Unrecognized attribute name [%d] was specific at WGL context creation time!",
                          attribute_name);

                vkgl_assert_fail();

                result = false;
                goto end;
            }
        }

        /* Move on */
        attribute_list_traveller_ptr += 2 /* name, value */;
    }

    /* Sanity checks */
    if ((m_major_version != 3) ||
        (m_minor_version != 0  &&
         m_minor_version != 1  &&
         m_minor_version != 2) )
    {
        VKGL_LOG(VKGL::LogLevel::Error,
                 "The application requested an unsupported OpenGL context version (%d.%d)",
                 m_major_version,
                 m_minor_version);

        result = false;
        goto end;
    }

    if (m_n_layer_plane != 0)
    {
        VKGL_LOG(VKGL::LogLevel::Error,
                 "Non-zero layer planes are not supported by VKGL");

        result = false;
        goto end;
    }

    if (m_is_forward_compatible_context)
    {
        m_major_version = 3;
        m_minor_version = 2;
    }
    else
    {
        VKGL_LOG(VKGL::LogLevel::Warning,
                 "Non-forward-compatible GL context was requested: VKGL does not prevent apps from using deprecated functionality.");
    }

end:
    vkgl_assert(result);

    if (result)
    {
        /* Also update the global HDC->context map */
        std::lock_guard<std::mutex> lock(g_context_map_mutex);

        vkgl_assert(g_context_map.find(in_hdc) == g_context_map.end() );
        g_context_map[in_hdc] = this;
    }

    return result;
}

bool WGL::Context::init_gl_context()
{
    bool result = false;

    /* First, spawn a Vulkan backend instance we're going to use to translate all the GL calls to */
    m_vk_backend_ptr = OpenGL::VKBackend::create(this);

    if (m_vk_backend_ptr == nullptr)
    {
        vkgl_assert(m_vk_backend_ptr != nullptr);

        goto end;
    }

    /* Good to create the GL context instance, now that we have a functional backend instance. */
    m_gl_context_ptr = OpenGL::Context::create(reinterpret_cast<VKGL::IWSIContext*>             (this),
                                               dynamic_cast<OpenGL::IBackendGLCallbacks*>       (m_vk_backend_ptr.get() ),
                                               dynamic_cast<const OpenGL::IBackendCapabilities*>(m_vk_backend_ptr.get() ));

    if (m_gl_context_ptr == nullptr)
    {
        vkgl_assert(m_gl_context_ptr != nullptr);

        goto end;
    }

    /* Set up a one-directional backend -> frontend link */
    m_vk_backend_ptr->set_frontend_callback(dynamic_cast<const OpenGL::IContextObjectManagers*>(m_gl_context_ptr.get() ));

    /* All done */
    result = true;
end:
    return result;
}

void WGL::Context::set_current_hdc(const HDC& in_hdc)
{
    if (m_current_hdc != in_hdc)
    {
        /* Update the global HDC->context map */
        {
            std::lock_guard<std::mutex> lock(g_context_map_mutex);

            if (in_hdc != nullptr)
            {
                g_context_map[in_hdc] = this;
            }

            if (m_current_hdc != nullptr)
            {
                g_context_map.erase(m_current_hdc);
            }
        }

        /* Update the HDC associated with the WGL context */
        m_current_hdc = in_hdc;

        /* Create a GL context, if none has been associated with this WGL context yet.
         *
         * NOTE: GL context initialization requires a non-null DC handle which is why this step
         *       is not performed at WGL context creation time.
         */
        if (m_gl_context_ptr == nullptr &&
            in_hdc           != nullptr)
        {
            bool result = init_gl_context();

            vkgl_assert(result);
        }

        /* Inform backend of the event */
        HWND hdc_window = ::WindowFromDC(in_hdc);

        m_vk_backend_ptr->set_target_window(hdc_window);
    }
}
