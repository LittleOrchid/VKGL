/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_uniform_3i.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLint&   in_location,
                     const GLint&   in_v0,
                     const GLint&   in_v1,
                     const GLint&   in_v2)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglUniform3i(GLint location,
                                          GLint v0,
                                          GLint v1,
                                          GLint v2)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniform3i(dispatch_table_ptr->bound_context_ptr,
                                     location,
                                     v0,
                                     v1,
                                     v2);
}

void vkglUniform3i_execute(VKGL::Context* in_context_ptr,
                           const GLint&   in_location,
                           const GLint&   in_v0,
                           const GLint&   in_v1,
                           const GLint&   in_v2)
{
    const GLint data[] =
    {
        in_v0,
        in_v1,
        in_v2
    };

    in_context_ptr->set_uniform(in_location,
                                VKGL::GetSetArgumentType::Int,
                                3,
                                data);
}

void vkglUniform3i_with_validation(VKGL::Context* in_context_ptr,
                                   const GLint&   in_location,
                                   const GLint&   in_v0,
                                   const GLint&   in_v1,
                                   const GLint&   in_v2)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_v0,
                 in_v1,
                 in_v2) )
    {
        vkglUniform3i_execute(in_context_ptr,
                              in_location,
                              in_v0,
                              in_v1,
                              in_v2);
    }
}
