/* ******************************************************************************** */

#include "./point.h"

/* ******************************************************************************** */

struct point createPoint(double _x, double _y, double _z, double _w){
    struct vec4 vec = createVec4_4d(_x, _y, _z, _w);

    struct point point;

    point.vtxArray = createVertexArray();
    insertPoint(&point.vtxArray, vec);

    return point;
}

/* ******************************************************************************** */

void preparePointForRender(struct point *point){
    glGenVertexArrays(1, &point->vtxArray.vao);
    glBindVertexArray(point->vtxArray.vao);

    glGenBuffers(1, &point->vtxArray.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, point->vtxArray.vbo);
    glBufferData(GL_ARRAY_BUFFER, vertexSizeof(&point->vtxArray),
        verticesRaw(&point->vtxArray), GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);

    glGenBuffers(1, &point->vtxArray.ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, point->vtxArray.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSizeof(&point->vtxArray),
        indicesRaw(&point->vtxArray), GL_DYNAMIC_DRAW);
}

/* ******************************************************************************** */

void renderPoint(struct point *point){
    glDrawElements(GL_POINTS, indiceCount(&point->vtxArray), GL_UNSIGNED_INT, 0);
}

/* ******************************************************************************** */