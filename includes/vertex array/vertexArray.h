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

#include "../varray/varray.h"
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

    struct varray vertices;
    struct iarray indices;

    int vao[1];
    int vbo[1];
    int ebo[1];
};

/* ******************************************************************************** */

struct vertexArray createVertexArray(enum arrayRenderType);
void destroyVertexArray(struct vertexArray*);

/* ******************************************************************************** */

int vertexSizeof(struct vertexArray*);
int indicesSizeof(struct vertexArray*);

/* ******************************************************************************** */

int vertexCount(struct vertexArray*);
int indiceCount(struct vertexArray*);

/* ******************************************************************************** */

float* verticesRaw(struct vertexArray*);
int* indicesRaw(struct vertexArray*);

/* ******************************************************************************** */

void preparevtx(struct vertexArray*);
void rendervtx(struct vertexArray*);

/* ******************************************************************************** */