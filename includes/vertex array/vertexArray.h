/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* ******************************************************************************** */

#include "../allocMacros.h"

/* ******************************************************************************** */

#include "../../glad/glad.h"
#include <GLFW/glfw3.h>

/* ******************************************************************************** */

#include "../farray/farray.h"
#include "../iarray/iarray.h"

/* ******************************************************************************** */

enum arrayRenderType {
    ARRAY_RENDER_TYPE_MIN = -1,

    POINTS      = GL_POINTS,
    LINES       = GL_LINES,
    TRIANGLES   = GL_TRIANGLES,
    TRI_FAN     = GL_TRIANGLE_FAN,

    ARRAY_RENDER_TYPE_MAX
};

/* ******************************************************************************** */

struct vertexArray {
    enum arrayRenderType renderType;

    struct farray vertices;
    struct farray colors;
    struct iarray indices;

    i32 vao[1];
    i32 vbo[1];
    i32 ebo[1];
};

/* ******************************************************************************** */

struct vertexArray createVertexArray(enum arrayRenderType);
none destroyVertexArray(struct vertexArray*);

/* ******************************************************************************** */

i32 sizeofVertices(struct vertexArray*);
i32 sizeofColors(struct vertexArray*);
i32 sizeofIndices(struct vertexArray*);

/* ******************************************************************************** */

i32 countVertices(struct vertexArray*);
i32 countColors(struct vertexArray*);
i32 countIndices(struct vertexArray*);

/* ******************************************************************************** */

f32* rawVertices(struct vertexArray*);
f32* rawColors(struct vertexArray*);
i32* rawIndices(struct vertexArray*);

/* ******************************************************************************** */

none prepareVertexArray(struct vertexArray*);
none renderVertexArray(struct vertexArray*);

/* ******************************************************************************** */