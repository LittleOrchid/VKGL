/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLEAR_DEPTH_H
#define VKGL_GL_CLEAR_DEPTH_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglClearDepth(GLdouble depth);

    void vkglClearDepth_with_validation(OpenGL::Context* in_context_ptr,
                                        const GLdouble&  in_depth);
}

#endif /* VKGL_GL_CLEAR_DEPTH_H */