/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_get_current_context.h"

HGLRC WINAPI WGL::get_current_context()
{
    VKGL_TRACE("wglGetCurrentContext()");

    return reinterpret_cast<HGLRC>(WGL::g_current_wgl_context_ptr);
}
