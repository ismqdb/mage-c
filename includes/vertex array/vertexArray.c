/* ******************************************************************************** */

#include "./vertexArray.h"

/* ******************************************************************************** */

struct vertexArray createVertexArray(enum arrayRenderType rtype){
    assert(rtype > ARRAY_RENDER_TYPE_MIN && rtype < ARRAY_RENDER_TYPE_MAX);

    struct vertexArray vertexArray;

    vertexArray.renderType = rtype;
    vertexArray.vertices  = createArray(ARRAY_FLOAT);
    vertexArray.indices =   createArray(ARRAY_INT);

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

void insertPoint(struct vertexArray *array, struct vec4 vec){
    insertFloat(&array->vertices, vec.x);
    insertFloat(&array->vertices, vec.y);
    insertFloat(&array->vertices, vec.z);
    insertFloat(&array->vertices, vec.w);
}

/* ******************************************************************************** */

void insertIndice(struct vertexArray *array, int indice){
    insertInt(&array->indices, indice);
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