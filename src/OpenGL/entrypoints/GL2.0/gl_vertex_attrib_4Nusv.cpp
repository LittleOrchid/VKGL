/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nusv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLushort*  in_v_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttrib4Nusv(GLuint          index,
                                                 const GLushort* v)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    /* TODO: Make me more useful */
    VKGL_TRACE("glVertexAttrib4Nusv(index=[%u] v=[%p])",
               index,
               v);

    dispatch_table_ptr->pGLVertexAttrib4Nusv(dispatch_table_ptr->bound_context_ptr,
                                             index,
                                             v);
}

static void vkglVertexAttrib4Nusv_execute(OpenGL::Context* in_context_ptr,
                                          const GLuint&    in_index,
                                          const GLushort*  in_v_ptr)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Unsigned_Short,
                                         OpenGL::GetSetArgumentType::Float,
                                         4,    /* in_n_components */
                                         true, /* in_normalized   */
                                         in_v_ptr);
}

void OpenGL::vkglVertexAttrib4Nusv_with_validation(OpenGL::Context* in_context_ptr,
                                                   const GLuint&    in_index,
                                                   const GLushort*  in_v_ptr)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_v_ptr) )
    {
        vkglVertexAttrib4Nusv_execute(in_context_ptr,
                                      in_index,
                                      in_v_ptr);
    }
}
