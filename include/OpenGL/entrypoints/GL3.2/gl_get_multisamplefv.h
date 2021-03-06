/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_MULTISAMPLEFV_H
#define VKGL_GL_GET_MULTISAMPLEFV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetMultisamplefv(GLenum   pname,
                                            GLuint   index,
                                            GLfloat* val);

    void vkglGetMultisamplefv_with_validation(OpenGL::Context* in_context_ptr,
                                              const GLenum&    in_pname,
                                              const GLuint&    in_index,
                                              GLfloat*         out_val_ptr);
}

#endif /* VKGL_GL_GET_MULTISAMPLEFV_H */