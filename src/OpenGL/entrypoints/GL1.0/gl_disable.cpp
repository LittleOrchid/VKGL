/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_disable.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_cap)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglDisable(GLenum cap)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glDisable(cap=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(cap) );

    dispatch_table_ptr->pGLDisable(dispatch_table_ptr->bound_context_ptr,
                                   cap);
}

static void vkglDisable_execute(OpenGL::Context* in_context_ptr,
                                const GLenum&    in_cap)
{
    const auto cap_vkgl = OpenGL::Utils::get_nonindexed_capability_for_gl_enum(in_cap);

    in_context_ptr->disable(cap_vkgl);
}

void OpenGL::vkglDisable_with_validation(OpenGL::Context* in_context_ptr,
                                         const GLenum&    in_cap)
{
    if (validate(in_context_ptr,
                 in_cap) )
    {
        vkglDisable_execute(in_context_ptr,
                            in_cap);
    }
}