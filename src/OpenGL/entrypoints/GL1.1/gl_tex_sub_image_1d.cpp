/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_tex_sub_image_1d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLint&     in_level,
                     const GLint&     in_xoffset,
                     const GLsizei&   in_width,
                     const GLenum&    in_format,
                     const GLenum&    in_type,
                     const void*      in_pixels)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglTexSubImage1D(GLenum      target,
                                             GLint       level,
                                             GLint       xoffset,
                                             GLsizei     width,
                                             GLenum      format,
                                             GLenum      type,
                                             const void* pixels)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glTexSubImage1D(target=[%s] level=[%d] xoffset=[%d] width=[%d] format=[%s] type=[%s] pixels=[%p])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               level,
               xoffset,
               static_cast<int32_t>(width),
               OpenGL::Utils::get_raw_string_for_gl_enum(format),
               OpenGL::Utils::get_raw_string_for_gl_enum(type),
               pixels);

    dispatch_table_ptr->pGLTexSubImage1D(dispatch_table_ptr->bound_context_ptr,
                                         target,
                                         level,
                                         xoffset,
                                         width,
                                         format,
                                         type,
                                         pixels);
}

static void vkglTexSubImage1D_execute(OpenGL::Context* in_context_ptr,
                                      const GLenum&    in_target,
                                      const GLint&     in_level,
                                      const GLint&     in_xoffset,
                                      const GLsizei&   in_width,
                                      const GLenum&    in_format,
                                      const GLenum&    in_type,
                                      const void*      in_pixels)
{
    const auto target_vkgl = OpenGL::Utils::get_texture_target_for_gl_enum(in_target);
    const auto format_vkgl = OpenGL::Utils::get_pixel_format_for_gl_enum  (in_format);
    const auto type_vkgl   = OpenGL::Utils::get_pixel_type_for_gl_enum    (in_type);

    in_context_ptr->tex_sub_image_1d(target_vkgl,
                                     in_level,
                                     in_xoffset,
                                     in_width,
                                     format_vkgl,
                                     type_vkgl,
                                     in_pixels);
}

void OpenGL::vkglTexSubImage1D_with_validation(OpenGL::Context* in_context_ptr,
                                               const GLenum&    in_target,
                                               const GLint&     in_level,
                                               const GLint&     in_xoffset,
                                               const GLsizei&   in_width,
                                               const GLenum&    in_format,
                                               const GLenum&    in_type,
                                               const void*      in_pixels)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_xoffset,
                 in_width,
                 in_format,
                 in_type,
                 in_pixels) )
    {
        vkglTexSubImage1D_execute(in_context_ptr,
                                  in_target,
                                  in_level,
                                  in_xoffset,
                                  in_width,
                                  in_format,
                                  in_type,
                                  in_pixels);
    }
}