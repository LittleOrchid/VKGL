/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_get_buffer_pointerv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLenum&    in_pname,
                     void**           out_params_ptr_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGetBufferPointerv(GLenum target,
                                                 GLenum pname,
                                                 void** params)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glGetBufferPointerv(target=[%s] pname=[%s] params=[%p])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               OpenGL::Utils::get_raw_string_for_gl_enum(pname),
               params);

    dispatch_table_ptr->pGLGetBufferPointerv(dispatch_table_ptr->bound_context_ptr,
                                             target,
                                             pname,
                                             params);
}

static void vkglGetBufferPointerv_execute(OpenGL::Context* in_context_ptr,
                                          const GLenum&    in_target,
                                          const GLenum&    in_pname,
                                          void**           out_params_ptr_ptr)
{
    const auto pname_vkgl  = OpenGL::Utils::get_buffer_pointer_property_for_gl_enum(in_pname);
    const auto target_vkgl = OpenGL::Utils::get_buffer_target_for_gl_enum          (in_target);

    in_context_ptr->get_buffer_pointerv(target_vkgl,
                                        pname_vkgl,
                                        out_params_ptr_ptr);
}

void OpenGL::vkglGetBufferPointerv_with_validation(OpenGL::Context* in_context_ptr,
                                                   const GLenum&    in_target,
                                                   const GLenum&    in_pname,
                                                   void**           out_params_ptr_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_pname,
                 out_params_ptr_ptr) )
    {
        vkglGetBufferPointerv_execute(in_context_ptr,
                                      in_target,
                                      in_pname,
                                      out_params_ptr_ptr);
    }
}
