/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_cull_face.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_mode)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglCullFace(GLenum mode)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glCullFace(mode=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(mode) );

    dispatch_table_ptr->pGLCullFace(dispatch_table_ptr->bound_context_ptr,
                                    mode);
}

static void vkglCullFace_execute(OpenGL::Context* in_context_ptr,
                                 const GLenum&    in_mode)
{
    const auto mode_vkgl = OpenGL::Utils::get_cull_mode_for_gl_enum(in_mode);

    in_context_ptr->set_cull_mode(mode_vkgl);
}

void OpenGL::vkglCullFace_with_validation(OpenGL::Context* in_context_ptr,
                                          const GLenum&    in_mode)
{
    if (validate(in_context_ptr,
                 in_mode) )
    {
        vkglCullFace_execute(in_context_ptr,
                             in_mode);
    }
}