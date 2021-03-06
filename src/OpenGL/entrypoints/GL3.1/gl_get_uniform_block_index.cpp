/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_get_uniform_block_index.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     GLuint           in_program,
                     const GLchar*    in_uniform_block_name)
{
    bool result = false;

    // ...

    result = true;
    return result;
}

GLuint VKGL_APIENTRY OpenGL::vkglGetUniformBlockIndex(GLuint        program,
                                                      const GLchar* uniformBlockName)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glGetUniformBlockIndex(program=[%u] uniformBlockName=[%s])",
               program,
               uniformBlockName);

    return dispatch_table_ptr->pGLGetUniformBlockIndex(dispatch_table_ptr->bound_context_ptr,
                                                       program,
                                                       uniformBlockName);
}

static GLuint vkglGetUniformBlockIndex_execute(OpenGL::Context* in_context_ptr,
                                               const GLuint&    in_program,
                                               const GLchar*    in_uniform_block_name)
{
    return in_context_ptr->get_uniform_block_index(in_program,
                                                   in_uniform_block_name);
}

GLuint OpenGL::vkglGetUniformBlockIndex_with_validation(OpenGL::Context* in_context_ptr,
                                                        const GLuint&    in_program,
                                                        const GLchar*    in_uniform_block_name)
{
    GLuint result = UINT32_MAX;

    if (validate(in_context_ptr,
                 in_program,
                 in_uniform_block_name) )
    {
        result = vkglGetUniformBlockIndex_execute(in_context_ptr,
                                                  in_program,
                                                  in_uniform_block_name);
    }

    return result;
}
