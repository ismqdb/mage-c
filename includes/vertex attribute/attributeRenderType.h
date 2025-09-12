/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../../glad/glad.h"
#include <GLFW/glfw3.h>

/* ******************************************************************************** */

enum attributeRenderType {
    ATTRIBUTE_RENDER_TYPE_MIN = -1,

    ATTRIBUTE_RENDER_STATIC  = GL_STATIC_DRAW,
    ATTRIBUTE_RENDER_DYNAMIC = GL_DYNAMIC_DRAW, 

    ATTRIBUTE_RENDER_TYPE_MAX
};

/* ******************************************************************************** */

