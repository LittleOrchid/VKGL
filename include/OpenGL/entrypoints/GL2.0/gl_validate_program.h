/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VALIDATE_PROGRAM_H
#define VKGL_GL_VALIDATE_PROGRAM_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglValidateProgram(GLuint program);

    void vkglValidateProgram_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLuint&    in_program);
}

#endif /* VKGL_GL_VALIDATE_PROGRAM_H */