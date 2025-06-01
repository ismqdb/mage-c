/* ******************************************************************************** */

#include "./vertexArray.h"

/* ******************************************************************************** */

struct vertexArray createVertexArray(){
    struct vertexArray vertexArray;

    vertexArray.vertices  = createArray(ARRAY_DOUBLE);
    vertexArray.indices =   createArray(ARRAY_INT);

    vertexArray.vao = -1;
    vertexArray.vbo = -1;
    vertexArray.ebo = -1;

    return vertexArray;
}

/* ******************************************************************************** */

void destroyVertexArray(struct vertexArray *vertexArray){
    destroyArray(&vertexArray->vertices);
    destroyArray(&vertexArray->indices);

    vertexArray->vao = -1;
    vertexArray->vbo = -1;
    vertexArray->ebo = -1;
}

/* ******************************************************************************** */

void insertPoint(struct vertexArray *array, struct vec4 vec){
    insertDouble(&array->vertices, vec.x);
    insertDouble(&array->vertices, vec.y);
    insertDouble(&array->vertices, vec.z);
    insertDouble(&array->vertices, vec.w);
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

double* verticesRaw(struct vertexArray *array){
    return (double*)getBytes(&array->vertices);
}

/* ******************************************************************************** */

int* indicesRaw(struct vertexArray *array){
    return (int*)getBytes(&array->indices);
}

/* ******************************************************************************** */