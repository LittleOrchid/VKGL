/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_3uiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLuint*  in_v_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglVertexAttribI3uiv(GLuint        index,
                                                  const GLuint* v)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttribI3uiv(dispatch_table_ptr->bound_context_ptr,
                                             index,
                                             v);
}

void vkglVertexAttribI3uiv_execute(VKGL::Context* in_context_ptr,
                                   const GLuint&  in_index,
                                   const GLuint*  in_v_ptr)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Unsigned_Int,
                                         VKGL::GetSetArgumentType::Unsigned_Int,
                                         3,
                                         false, /* in_normalized */
                                         in_v_ptr);
}

void vkglVertexAttribI3uiv_with_validation(VKGL::Context* in_context_ptr,
                                           const GLuint&  in_index,
                                           const GLuint*  in_v_ptr)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_v_ptr) )
    {
        vkglVertexAttribI3uiv_execute(in_context_ptr,
                                      in_index,
                                      in_v_ptr);
    }
}
