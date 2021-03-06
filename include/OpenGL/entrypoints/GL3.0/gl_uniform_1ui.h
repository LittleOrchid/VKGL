/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_1UI_H
#define VKGL_GL_UNIFORM_1UI_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglUniform1ui(GLint  location,
                                      GLuint v0);

    void vkglUniform1ui_with_validation(OpenGL::Context* in_context_ptr,
                                        const GLint&     in_location,
                                        const GLuint&    in_v0);
}

#endif /* VKGL_GL_UNIFORM_1UI_H */