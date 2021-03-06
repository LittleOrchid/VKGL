/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_draw_range_elements_base_vertex.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_mode,
                     const GLuint&    in_start,
                     const GLuint&    in_end,
                     const GLsizei&   in_count,
                     const GLenum&    in_type,
                     const void*      in_indices,
                     const GLint&     in_basevertex)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDrawRangeElementsBaseVertex(GLenum      mode,
                                                           GLuint      start,
                                                           GLuint      end,
                                                           GLsizei     count,
                                                           GLenum      type,
                                                           const void* indices,
                                                           GLint       basevertex)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glDrawRangeElementsBaseVertex(mode=[%s] start=%u] end=[%u] count=[%d] type=[%s] indices=[%p] basevertex=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(mode),
               start,
               end,
               static_cast<int32_t>(count),
               OpenGL::Utils::get_raw_string_for_gl_enum(type),
               indices,
               basevertex);

    dispatch_table_ptr->pGLDrawRangeElementsBaseVertex(dispatch_table_ptr->bound_context_ptr,
                                                       mode,
                                                       start,
                                                       end,
                                                       count,
                                                       type,
                                                       indices,
                                                       basevertex);
}


static void vkglDrawRangeElementsBaseVertex_execute(OpenGL::Context* in_context_ptr,
                                                    const GLenum&    in_mode,
                                                    const GLuint&    in_start,
                                                    const GLuint&    in_end,
                                                    const GLsizei&   in_count,
                                                    const GLenum&    in_type,
                                                    const void*      in_indices,
                                                    const GLint&     in_basevertex)
{
    const auto mode_vkgl = OpenGL::Utils::get_draw_call_mode_for_gl_enum      (in_mode);
    const auto type_vkgl = OpenGL::Utils::get_draw_call_index_type_for_gl_enum(in_type);

    in_context_ptr->draw_range_elements_base_vertex(mode_vkgl,
                                                    in_start,
                                                    in_end,
                                                    in_count,
                                                    type_vkgl,
                                                    in_indices,
                                                    in_basevertex);
}

void OpenGL::vkglDrawRangeElementsBaseVertex_with_validation(OpenGL::Context* in_context_ptr,
                                                             const GLenum&    in_mode,
                                                             const GLuint&    in_start,
                                                             const GLuint&    in_end,
                                                             const GLsizei&   in_count,
                                                             const GLenum&    in_type,
                                                             const void*      in_indices,
                                                             const GLint&     in_basevertex)
{
    if (validate(in_context_ptr,
                 in_mode,
                 in_start,
                 in_end,
                 in_count,
                 in_type,
                 in_indices,
                 in_basevertex) )
    {
        vkglDrawRangeElementsBaseVertex_execute(in_context_ptr,
                                                in_mode,
                                                in_start,
                                                in_end,
                                                in_count,
                                                in_type,
                                                in_indices,
                                                in_basevertex);
    }
}
