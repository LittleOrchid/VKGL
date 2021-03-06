/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_texture_layer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLenum&    in_attachment,
                     const GLuint&    in_texture,
                     const GLint&     in_level,
                     const GLint&     in_layer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglFramebufferTextureLayer(GLenum target,
                                                       GLenum attachment,
                                                       GLuint texture,
                                                       GLint  level,
                                                       GLint  layer)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glFramebufferTextureLayer(target=[%s] attachment=[%s] texture=[%u] level=[%d] layer=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               OpenGL::Utils::get_raw_string_for_gl_enum(attachment),
               texture,
               level,
               layer);

    dispatch_table_ptr->pGLFramebufferTextureLayer(dispatch_table_ptr->bound_context_ptr,
                                                   target,
                                                   attachment,
                                                   texture,
                                                   level,
                                                   layer);
}

static void vkglFramebufferTextureLayer_execute(OpenGL::Context* in_context_ptr,
                                                const GLenum&    in_target,
                                                const GLenum&    in_attachment,
                                                const GLuint&    in_texture,
                                                const GLint&     in_level,
                                                const GLint&     in_layer)
{
    const auto attachment_vkgl = OpenGL::Utils::get_framebuffer_attachment_point_for_gl_enum(in_attachment);
    const auto target_vkgl     = OpenGL::Utils::get_framebuffer_target_for_gl_enum          (in_target);

    in_context_ptr->framebuffer_texture_layer(target_vkgl,
                                              attachment_vkgl,
                                              in_texture,
                                              in_level,
                                              in_layer);
}

void OpenGL::vkglFramebufferTextureLayer_with_validation(OpenGL::Context* in_context_ptr,
                                                         const GLenum&    in_target,
                                                         const GLenum&    in_attachment,
                                                         const GLuint&    in_texture,
                                                         const GLint&     in_level,
                                                         const GLint&     in_layer)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_attachment,
                 in_texture,
                 in_level,
                 in_layer) )
    {
        vkglFramebufferTextureLayer_execute(in_context_ptr,
                                            in_target,
                                            in_attachment,
                                            in_texture,
                                            in_level,
                                            in_layer);
    }
}
