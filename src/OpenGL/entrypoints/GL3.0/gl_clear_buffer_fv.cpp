/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_clear_buffer_fv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_buffer,
                     const GLint&     in_drawbuffer,
                     const GLfloat*   in_value_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglClearBufferfv(GLenum         buffer,
                                             GLint          drawbuffer,
                                             const GLfloat* value)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glClearBufferfv(buffer=[%s] drawbuffer=[%d] *value=[%.4f])",
               OpenGL::Utils::get_raw_string_for_gl_enum(buffer),
               drawbuffer,
              *value);

    dispatch_table_ptr->pGLClearBufferfv(dispatch_table_ptr->bound_context_ptr,
                                         buffer,
                                         drawbuffer,
                                         value);
}

static void vkglClearBufferfv_execute(OpenGL::Context* in_context_ptr,
                                      const GLenum&    in_buffer,
                                      const GLint&     in_drawbuffer,
                                      const GLfloat*   in_value_ptr)
{
    const auto     buffer_vkgl  = OpenGL::Utils::get_clear_buffer_for_gl_enum(in_buffer);
    const auto     depth_value  = (in_buffer == GL_DEPTH) ? *in_value_ptr : 0.0f;
    const uint32_t n_components = (in_buffer == GL_DEPTH) ? 0             : 4;

    in_context_ptr->clear_buffer(buffer_vkgl,
                                 in_drawbuffer,
                                 OpenGL::GetSetArgumentType::Float,
                                 n_components,
                                 in_value_ptr,
                                 0,
                                 0);
}

void OpenGL::vkglClearBufferfv_with_validation(OpenGL::Context* in_context_ptr,
                                               const GLenum&    in_buffer,
                                               const GLint&     in_drawbuffer,
                                               const GLfloat*   in_value_ptr)
{
    if (validate(in_context_ptr,
                 in_buffer,
                 in_drawbuffer,
                 in_value_ptr) )
    {
        vkglClearBufferfv_execute(in_context_ptr,
                                  in_buffer,
                                  in_drawbuffer,
                                  in_value_ptr);
    }
}
