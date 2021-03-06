/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1s.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLshort&   in_x)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttrib1s(GLuint  index,
                                              GLshort x)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glVertexAttrib1s(index=[%u] x=[%d])",
               index,
               static_cast<int32_t>(x) );

    dispatch_table_ptr->pGLVertexAttrib1s(dispatch_table_ptr->bound_context_ptr,
                                          index,
                                          x);
}

static void vkglVertexAttrib1s_execute(OpenGL::Context* in_context_ptr,
                                       const GLuint&    in_index,
                                       const GLshort&   in_x)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Short,
                                         OpenGL::GetSetArgumentType::Float,
                                         1,     /* in_n_components */
                                         false, /* in_normalized   */
                                        &in_x);
}

void OpenGL::vkglVertexAttrib1s_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLuint&    in_index,
                                                const GLshort&   in_x)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x) )
    {
        vkglVertexAttrib1s_execute(in_context_ptr,
                                   in_index,
                                   in_x);
    }
}
