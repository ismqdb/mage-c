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

#include "../vertex attribute/vertexAttribute.h"

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

    struct vertexAttribute position;
    struct vertexAttribute color;
    struct vertexAttribute model;

    struct array indices;

    i32 vao[1];
    i32 ebo[1];
    
    i32 program;
};

/* ******************************************************************************** */

struct vertexArray createVertexArray(enum arrayRenderType, i32);
none destroyVertexArray(struct vertexArray*);

/* ******************************************************************************** */

none createVAO(struct vertexArray*);
none bindVAO(struct vertexArray*);

/* ******************************************************************************** */

none fillElementBuffer(struct vertexArray*);

/* ******************************************************************************** */

none prepareVertexArray(struct vertexArray*);

/* ******************************************************************************** */

none renderVertexArray(struct vertexArray*);
none renderVertexArrayInstanced(struct vertexArray*, i32);

/* ******************************************************************************** */