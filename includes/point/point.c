/* ******************************************************************************** */

#include "./point.h"

/* ******************************************************************************** */

struct point createPoint(double _x, double _y, double _z, double _w){
    struct vec4 vec = createVec4_4d(_x, _y, _z, _w);

    struct point point;

    point.vtxArray = createVertexArray(GL_POINTS);
    insertPoint(&point.vtxArray, vec);
    insertIndice(&point.vtxArray, 0);

    return point;
}

/* ******************************************************************************** */

void preparePointForRender(struct point *point){
    glGenVertexArrays(1, point->vtxArray.vao);
    glBindVertexArray(point->vtxArray.vao[0]);
    
    glGenBuffers(1, point->vtxArray.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, point->vtxArray.vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, vertexSizeof(&point->vtxArray), 
        verticesRaw(&point->vtxArray), GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);
    
    glGenBuffers(1, point->vtxArray.ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, point->vtxArray.ebo[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSizeof(&point->vtxArray),
        indicesRaw(&point->vtxArray), GL_DYNAMIC_DRAW);
}

/* ******************************************************************************** */

void renderPoint(struct point *point){
    glDrawElements(point->vtxArray.renderType, 1, GL_UNSIGNED_INT, (void*)0);
}

/* ******************************************************************************** */