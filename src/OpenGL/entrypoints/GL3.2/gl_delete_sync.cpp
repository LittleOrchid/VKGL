/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_delete_sync.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLsync&    in_sync)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDeleteSync(GLsync sync)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glDeleteSync(sync=[%p])",
               sync);

    dispatch_table_ptr->pGLDeleteSync(dispatch_table_ptr->bound_context_ptr,
                                      sync);
}

static void vkglDeleteSync_execute(OpenGL::Context* in_context_ptr,
                                   const GLsync&    in_sync)
{
    in_context_ptr->delete_sync(in_sync);
}

void OpenGL::vkglDeleteSync_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLsync&    in_sync)
{
    if (validate(in_context_ptr,
                 in_sync) )
    {
        vkglDeleteSync_execute(in_context_ptr,
                               in_sync);
    }
}
