/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_3UIV_H
#define VKGL_GL_UNIFORM_3UIV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglUniform3uiv(GLint         location,
                                       GLsizei       count,
                                       const GLuint* value);

    void vkglUniform3uiv_with_validation(OpenGL::Context* in_context_ptr,
                                         const GLint&     in_location,
                                         const GLsizei&   in_count,
                                         const GLuint*    in_value_ptr);
}

#endif /* VKGL_GL_UNIFORM_3UIV_H */