/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_draw_elements_instanced.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_mode,
                     const GLsizei&   in_count,
                     const GLenum&    in_type,
                     const void*      in_indices_ptr,
                     const GLsizei&   in_instancecount)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDrawElementsInstanced(GLenum      mode,
                                                     GLsizei     count,
                                                     GLenum      type,
                                                     const void* indices,
                                                     GLsizei     instancecount)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glDrawElementsInstanced(mode=[%s] count=[%d] type=[%s] indices=[%p] instancecount=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(mode),
               static_cast<int32_t>(count),
               OpenGL::Utils::get_raw_string_for_gl_enum(type),
               indices,
               static_cast<int32_t>(instancecount) );

    dispatch_table_ptr->pGLDrawElementsInstanced(dispatch_table_ptr->bound_context_ptr,
                                                 mode,
                                                 count,
                                                 type,
                                                 indices,
                                                 instancecount);
}

static void vkglDrawElementsInstanced_execute(OpenGL::Context* in_context_ptr,
                                              const GLenum&    in_mode,
                                              const GLsizei&   in_count,
                                              const GLenum&    in_type,
                                              const void*      in_indices_ptr,
                                              const GLsizei&   in_instancecount)
{
    const auto mode_vkgl = OpenGL::Utils::get_draw_call_mode_for_gl_enum      (in_mode);
    const auto type_vkgl = OpenGL::Utils::get_draw_call_index_type_for_gl_enum(in_type);

    in_context_ptr->draw_elements_instanced(mode_vkgl,
                                            in_count,
                                            type_vkgl,
                                            in_indices_ptr,
                                            in_instancecount);
}

void OpenGL::vkglDrawElementsInstanced_with_validation(OpenGL::Context* in_context_ptr,
                                                       const GLenum&    in_mode,
                                                       const GLsizei&   in_count,
                                                       const GLenum&    in_type,
                                                       const void*      in_indices_ptr,
                                                       const GLsizei&   in_instancecount)
{
    if (validate(in_context_ptr,
                 in_mode,
                 in_count,
                 in_type,
                 in_indices_ptr,
                 in_instancecount) )
    {
        vkglDrawElementsInstanced_execute(in_context_ptr,
                                          in_mode,
                                          in_count,
                                          in_type,
                                          in_indices_ptr,
                                          in_instancecount);
    }
}
