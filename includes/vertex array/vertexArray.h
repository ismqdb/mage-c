/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* ******************************************************************************** */

#include "../allocMacros.h"

/* ******************************************************************************** */

#include "../array/array.h"
#include "../vec4/vec4.h"

/* ******************************************************************************** */

struct vertexArray createVertexArray();
void destroyVertexArray(struct vertexArray*);

/* ******************************************************************************** */

void insertPoint(struct vertexArray*, struct vec4);
void insertIndice(struct vertexArray*, int);

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

struct vertexArray {
    struct array vertices;
    struct array indices;

    int vao[1];
    int vbo[1];
    int ebo[1];
};

/* ******************************************************************************** */