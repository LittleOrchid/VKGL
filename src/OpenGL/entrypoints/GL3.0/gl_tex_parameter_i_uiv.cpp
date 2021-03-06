/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_tex_parameter_i_uiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLenum&    in_pname,
                     const GLuint*    in_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglTexParameterIuiv(GLenum        target,
                                                GLenum        pname,
                                                const GLuint* params)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glTexParameterIuiv(target=[%s] pname=[%s] params=[%p])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               OpenGL::Utils::get_raw_string_for_gl_enum(pname),
               params);

    dispatch_table_ptr->pGLTexParameterIuiv(dispatch_table_ptr->bound_context_ptr,
                                            target,
                                            pname,
                                            params);
}

static void vkglTexParameterIuiv_execute(OpenGL::Context* in_context_ptr,
                                         const GLenum&    in_target,
                                         const GLenum&    in_pname,
                                         const GLuint*    in_params_ptr)
{
    const auto pname_vkgl  = OpenGL::Utils::get_texture_property_for_gl_enum(in_pname);
    const auto target_vkgl = OpenGL::Utils::get_texture_target_for_gl_enum  (in_target);

    in_context_ptr->set_texture_parameter(target_vkgl,
                                          pname_vkgl,
                                          OpenGL::GetSetArgumentType::Unsigned_Int,
                                          in_params_ptr);
}

void OpenGL::vkglTexParameterIuiv_with_validation(OpenGL::Context* in_context_ptr,
                                                  const GLenum&    in_target,
                                                  const GLenum&    in_pname,
                                                  const GLuint*    in_params_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_pname,
                 in_params_ptr) )
    {
        vkglTexParameterIuiv_execute(in_context_ptr,
                                     in_target,
                                     in_pname,
                                     in_params_ptr);
    }
}
