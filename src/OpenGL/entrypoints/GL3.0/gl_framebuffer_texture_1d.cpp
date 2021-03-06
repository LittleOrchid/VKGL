/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_texture_1d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLenum&    in_attachment,
                     const GLenum&    in_textarget,
                     const GLuint&    in_texture,
                     const GLint&     in_level)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglFramebufferTexture1D(GLenum target,
                                                    GLenum attachment,
                                                    GLenum textarget,
                                                    GLuint texture,
                                                    GLint  level)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glFramebufferTexture1D(target=[%s] attachment=[%s] textarget=[%s] texture=[%u] level=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               OpenGL::Utils::get_raw_string_for_gl_enum(attachment),
               OpenGL::Utils::get_raw_string_for_gl_enum(textarget),
               texture,
               level);

    dispatch_table_ptr->pGLFramebufferTexture1D(dispatch_table_ptr->bound_context_ptr,
                                                target,
                                                attachment,
                                                textarget,
                                                texture,
                                                level);
}

static void vkglFramebufferTexture1D_execute(OpenGL::Context* in_context_ptr,
                                             const GLenum&    in_target,
                                             const GLenum&    in_attachment,
                                             const GLenum&    in_textarget,
                                             const GLuint&    in_texture,
                                             const GLint&     in_level)
{
    const auto attachment_vkgl = OpenGL::Utils::get_framebuffer_attachment_point_for_gl_enum(in_attachment);
    const auto target_vkgl     = OpenGL::Utils::get_framebuffer_target_for_gl_enum          (in_target);
    const auto textarget_vkgl  = OpenGL::Utils::get_texture_target_for_gl_enum              (in_textarget);

    in_context_ptr->framebuffer_texture_1D(target_vkgl,
                                           attachment_vkgl,
                                           textarget_vkgl,
                                           in_texture,
                                           in_level);
}

void OpenGL::vkglFramebufferTexture1D_with_validation(OpenGL::Context* in_context_ptr,
                                                      const GLenum&    in_target,
                                                      const GLenum&    in_attachment,
                                                      const GLenum&    in_textarget,
                                                      const GLuint&    in_texture,
                                                      const GLint&     in_level)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_attachment,
                 in_textarget,
                 in_texture,
                 in_level) )
    {
        vkglFramebufferTexture1D_execute(in_context_ptr,
                                         in_target,
                                         in_attachment,
                                         in_textarget,
                                         in_texture,
                                         in_level);
    }
}
