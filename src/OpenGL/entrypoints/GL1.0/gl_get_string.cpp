/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_get_string.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_name)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


const GLubyte* APIENTRY OpenGL::vkglGetString(GLenum name)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glGetString(name=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(name) );

    return dispatch_table_ptr->pGLGetString(dispatch_table_ptr->bound_context_ptr,
                                            name);
}

static const GLubyte* vkglGetString_execute(OpenGL::Context* in_context_ptr,
                                            const GLenum&    in_name)
{
    const auto     name_vkgl  = OpenGL::Utils::get_context_property_for_gl_enum(in_name);
    const GLubyte* result_ptr = nullptr;

    in_context_ptr->get_parameter(name_vkgl,
                                  OpenGL::GetSetArgumentType::String,
                                 &result_ptr);

    return result_ptr;
}

const GLubyte* OpenGL::vkglGetString_with_validation(OpenGL::Context* in_context_ptr,
                                                     const GLenum&    in_name)
{
    const GLubyte* result_ptr = nullptr;

    if (validate(in_context_ptr,
                 in_name) )
    {
        result_ptr = vkglGetString_execute(in_context_ptr,
                                           in_name);
    }

    return result_ptr;
}