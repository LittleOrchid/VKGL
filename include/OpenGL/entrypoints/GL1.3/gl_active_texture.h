/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_ACTIVE_TEXTURE_H
#define VKGL_GL_ACTIVE_TEXTURE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglActiveTexture(GLenum texture);

    void vkglActiveTexture_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLenum&    in_texture);
}

#endif /* VKGL_GL_ACTIVE_TEXTURE_H */