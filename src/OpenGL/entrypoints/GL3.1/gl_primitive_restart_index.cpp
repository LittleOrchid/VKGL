/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_primitive_restart_index.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglPrimitiveRestartIndex(GLuint index)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLPrimitiveRestartIndex(dispatch_table_ptr->bound_context_ptr,
                                                 index);
}

void vkglPrimitiveRestartIndex_execute(VKGL::Context* in_context_ptr,
                                       const GLuint&  in_index)
{
    in_context_ptr->set_primitive_restart_index(in_index);
}

void vkglPrimitiveRestartIndex_with_validation(VKGL::Context* in_context_ptr,
                                               const GLuint&  in_index)
{
    if (validate(in_context_ptr,
                 in_index) )
    {
        vkglPrimitiveRestartIndex_execute(in_context_ptr,
                                          in_index);
    }
}
