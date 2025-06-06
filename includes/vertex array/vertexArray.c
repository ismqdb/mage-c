/* ******************************************************************************** */

#include "./vertexArray.h"

/* ******************************************************************************** */

struct vertexArray createVertexArray(enum arrayRenderType rtype){
    assert(rtype > ARRAY_RENDER_TYPE_MIN && rtype < ARRAY_RENDER_TYPE_MAX);

    struct vertexArray vertexArray;

    vertexArray.renderType  = rtype;
    vertexArray.vertices    = createArray(ARRAY_FLOAT);
    vertexArray.indices     = createArray(ARRAY_INT);

    vertexArray.vao[0] = -1;
    vertexArray.vbo[0] = -1;
    vertexArray.ebo[0] = -1;

    return vertexArray;
}

/* ******************************************************************************** */

void destroyVertexArray(struct vertexArray *vertexArray){
    destroyArray(&vertexArray->vertices);
    destroyArray(&vertexArray->indices);

    vertexArray->vao[0] = -1;
    vertexArray->vbo[0] = -1;
    vertexArray->ebo[0] = -1;
}

/* ******************************************************************************** */

int vertexSizeof(struct vertexArray *array){
    return byteSize(&array->vertices);
}

/* ******************************************************************************** */

int indicesSizeof(struct vertexArray *array){
    return byteSize(&array->indices);
}

/* ******************************************************************************** */

int vertexCount(struct vertexArray *array){
    return array->vertices.size;
}

/* ******************************************************************************** */

int indiceCount(struct vertexArray *array){
    return array->indices.size;
}

/* ******************************************************************************** */

float* verticesRaw(struct vertexArray *array){
    return (float*)getBytes(&array->vertices);
}

/* ******************************************************************************** */

int* indicesRaw(struct vertexArray *array){
    return (int*)getBytes(&array->indices);
}

/* ******************************************************************************** */

void preparevtx(struct vertexArray* vtxarray){
    glGenVertexArrays(1, vtxarray->vao);
    glBindVertexArray(vtxarray->vao[0]);

    glGenBuffers(1, vtxarray->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vtxarray->vbo[0]);

    glBufferData(
        GL_ARRAY_BUFFER,
        vertexSizeof(vtxarray),
        verticesRaw(vtxarray),
        GL_DYNAMIC_DRAW
    );

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, vtxarray->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vtxarray->ebo[0]);

    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        indicesSizeof(vtxarray),
        indicesRaw(vtxarray),
        GL_DYNAMIC_DRAW
    );
}

/* ******************************************************************************** */

void rendervtx(struct vertexArray* vtxarray){
    glDrawElements(
        vtxarray->renderType, 
        indiceCount(vtxarray), 
        GL_UNSIGNED_INT, 
        NULL
    );
}

/* ******************************************************************************** */