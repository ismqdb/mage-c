/* ******************************************************************************** */

#include "./vertexArray.h"

/* ******************************************************************************** */

struct vertexArray createVertexArray(enum arrayRenderType rtype){
    assert(rtype > ARRAY_RENDER_TYPE_MIN && rtype < ARRAY_RENDER_TYPE_MAX);

    struct vertexArray vertexArray;

    vertexArray.renderType  = rtype;
    vertexArray.vertices    = vcreateArray();
    vertexArray.indices     = icreateArray();

    vertexArray.vao[0] = -1;
    vertexArray.vbo[0] = -1;
    vertexArray.ebo[0] = -1;

    return vertexArray;
}

/* ******************************************************************************** */

void destroyVertexArray(struct vertexArray *vertexArray){
    vdestroyArray(&vertexArray->vertices);
    idestroyArray(&vertexArray->indices);

    vertexArray->vao[0] = -1;
    vertexArray->vbo[0] = -1;
    vertexArray->ebo[0] = -1;
}

/* ******************************************************************************** */

i32 vertexSizeof(struct vertexArray *array){
    return vbyteSize(&array->vertices);
}

/* ******************************************************************************** */

i32 indicesSizeof(struct vertexArray *array){
    return ibyteSize(&array->indices);
}

/* ******************************************************************************** */

i32 vertexCount(struct vertexArray *array){
    return array->vertices.size;
}

/* ******************************************************************************** */

i32 indiceCount(struct vertexArray *array){
    return array->indices.size;
}

/* ******************************************************************************** */

f32* verticesRaw(struct vertexArray *array){
    return (f32*)vgetBytes(&array->vertices);
}

/* ******************************************************************************** */

i32* indicesRaw(struct vertexArray *array){
    return (i32*)igetBytes(&array->indices);
}

/* ******************************************************************************** */

void appendVertices(struct vertexArray *vtxarray, struct varray *vertices){
    for(i32 i = 0; i < vertices->size; i++)
        insertFloat(&vtxarray->vertices, vertices->elems[i]);
}

/* ******************************************************************************** */

void appendIndices(struct vertexArray *vtxarray, struct iarray *indices){
    for(i32 i = 0; i < indices->size; i++)
        insertInt(&vtxarray->indices, indices->elems[i]);
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