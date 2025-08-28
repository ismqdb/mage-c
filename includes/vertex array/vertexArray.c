/* ******************************************************************************** */

#include "./vertexArray.h"

/* ******************************************************************************** */

struct vertexArray createVertexArray(enum arrayRenderType rtype){
    assert(rtype > ARRAY_RENDER_TYPE_MIN && rtype < ARRAY_RENDER_TYPE_MAX);

    struct vertexArray vertexArray;

    vertexArray.renderType  = rtype;
    vertexArray.vertices    = fcreateArray();
    vertexArray.colors      = fcreateArray();
    vertexArray.indices     = icreateArray();

    vertexArray.vao[0] = -1;
    vertexArray.vbo[0] = -1;
    vertexArray.ebo[0] = -1;

    return vertexArray;
}

/* ******************************************************************************** */

void destroyVertexArray(struct vertexArray *vertexArray){
    fdestroyArray(&vertexArray->vertices);
    fdestroyArray(&vertexArray->colors);
    idestroyArray(&vertexArray->indices);

    vertexArray->vao[0] = -1;
    vertexArray->vbo[0] = -1;
    vertexArray->ebo[0] = -1;
}

/* ******************************************************************************** */

i32 sizeofVertices(struct vertexArray *array){
    return fbyteSize(&array->vertices);
}

/* ******************************************************************************** */

i32 sizeofColors(struct vertexArray *array){
    return fbyteSize(&array->colors);
}

/* ******************************************************************************** */

i32 sizeofIndices(struct vertexArray *array){
    return ibyteSize(&array->indices);
}

/* ******************************************************************************** */

i32 countVertices(struct vertexArray *array){
    return array->vertices.size;
}

/* ******************************************************************************** */

i32 countColors(struct vertexArray *array){
    return array->colors.size;
}

/* ******************************************************************************** */

i32 countIndices(struct vertexArray *array){
    return array->indices.size;
}

/* ******************************************************************************** */

f32* rawVertices(struct vertexArray *array){
    return (f32*)fgetBytes(&array->vertices);
}

/* ******************************************************************************** */

f32* rawColors(struct vertexArray *array){
    return (f32*)fgetBytes(&array->colors);
}

/* ******************************************************************************** */

i32* rawIndices(struct vertexArray *array){
    return (i32*)igetBytes(&array->indices);
}

/* ******************************************************************************** */

void appendVertices(struct vertexArray *array, struct farray *vertices){
    for(i32 i = 0; i < vertices->size; i++)
        insertFloat(&array->vertices, vertices->elems[i]);
}

/* ******************************************************************************** */

void appendColors(struct vertexArray *array, struct farray *colors){
    for(i32 i = 0; i < colors->size; i++)
        insertFloat(&array->colors, colors->elems[i]);
}

/* ******************************************************************************** */

void appendIndices(struct vertexArray *array, struct iarray *indices){
    for(i32 i = 0; i < indices->size; i++)
        insertIndice(&array->indices, indices->elems[i]);
}

/* ******************************************************************************** */

void prepareVertexArray(struct vertexArray *array){
    glGenVertexArrays(1, array->vao);
    glBindVertexArray(array->vao[0]);

    glGenBuffers(1, array->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, array->vbo[0]);

    glBufferData(
        GL_ARRAY_BUFFER,
        sizeofVertices(array),
        rawVertices(array),
        GL_DYNAMIC_DRAW
    );

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, array->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, array->ebo[0]);

    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        sizeofIndices(array),
        rawIndices(array),
        GL_DYNAMIC_DRAW
    );
}

/* ******************************************************************************** */

void renderVertexArray(struct vertexArray *array){
    glDrawElements(
        array->renderType, 
        countIndices(array), 
        GL_UNSIGNED_INT, 
        NULL
    );
}

/* ******************************************************************************** */