/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_BLOCK_BINDING_H
#define VKGL_GL_UNIFORM_BLOCK_BINDING_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniformBlockBinding(GLuint program,
                                           GLuint uniformBlockIndex,
                                           GLuint uniformBlockBinding);

#endif /* VKGL_GL_UNIFORM_BLOCK_BINDING_H */