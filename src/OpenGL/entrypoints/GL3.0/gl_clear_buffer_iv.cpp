/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_clear_buffer_iv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_buffer,
                     const GLint&   in_drawbuffer,
                     const GLint*   in_value_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglClearBufferiv(GLenum       buffer,
                                              GLint        drawbuffer,
                                              const GLint* value)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLClearBufferiv(dispatch_table_ptr->bound_context_ptr,
                                         buffer,
                                         drawbuffer,
                                         value);
}

void vkglClearBufferiv_execute(VKGL::Context* in_context_ptr,
                               const GLenum&  in_buffer,
                               const GLint&   in_drawbuffer,
                               const GLint*   in_value_ptr)
{
    const auto     buffer_vkgl   = VKGL::Utils::get_clear_buffer_for_gl_enum(in_buffer);
    const uint32_t n_components  = (in_buffer == GL_STENCIL) ? 0             : 4;
    const auto     stencil_value = (in_buffer == GL_STENCIL) ? *in_value_ptr : 0;

    in_context_ptr->clear_buffer(buffer_vkgl,
                                 in_drawbuffer,
                                 VKGL::GetSetArgumentType::Int,
                                 n_components,
                                 in_value_ptr,
                                 0,
                                 stencil_value);
}

void vkglClearBufferiv_with_validation(VKGL::Context* in_context_ptr,
                                       const GLenum&  in_buffer,
                                       const GLint&   in_drawbuffer,
                                       const GLint*   in_value_ptr)
{
    if (validate(in_context_ptr,
                 in_buffer,
                 in_drawbuffer,
                 in_value_ptr) )
    {
        vkglClearBufferiv_execute(in_context_ptr,
                                  in_buffer,
                                  in_drawbuffer,
                                  in_value_ptr);
    }
}
