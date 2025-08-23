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
    struct iarray indices;

    i32 vao[1];
    i32 vbo[1];
    i32 ebo[1];
};

/* ******************************************************************************** */

struct vertexArray createVertexArray(enum arrayRenderType);
void destroyVertexArray(struct vertexArray*);

/* ******************************************************************************** */

i32 vertexSizeof(struct vertexArray*);
i32 indicesSizeof(struct vertexArray*);

/* ******************************************************************************** */

i32 vertexCount(struct vertexArray*);
i32 indiceCount(struct vertexArray*);

/* ******************************************************************************** */

f32* verticesRaw(struct vertexArray*);
i32* indicesRaw(struct vertexArray*);

/* ******************************************************************************** */

void appendVertices(struct vertexArray*, struct farray*);
void appendIndices(struct vertexArray*, struct iarray*);

/* ******************************************************************************** */

void prepareVertexArray(struct vertexArray*);
void renderVertexArray(struct vertexArray*);

/* ******************************************************************************** */