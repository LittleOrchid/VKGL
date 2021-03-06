/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_FLOATV_H
#define VKGL_GL_GET_FLOATV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetFloatv(GLenum   pname,
                                     GLfloat* data);

    void vkglGetFloatv_with_validation(OpenGL::Context* in_context_ptr,
                                       const GLenum&    in_pname,
                                       GLfloat*         out_data_ptr);
}

#endif /* VKGL_GL_GET_FLOATV_H */