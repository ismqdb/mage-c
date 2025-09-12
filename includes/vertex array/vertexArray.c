/* ******************************************************************************** */

#include "./vertexArray.h"

/* ******************************************************************************** */

struct vertexArray createVertexArray(enum arrayRenderType type, i32 program){
    assert(type > ARRAY_RENDER_TYPE_MIN && type < ARRAY_RENDER_TYPE_MAX);

    struct vertexArray vertexArray;

    vertexArray.renderType  = type;
    vertexArray.program     = program;

    vertexArray.position = createVertexAttribute(
        ARRAY_TYPE_FLOAT, 
        VERTEX_ATTRIBUTE_TYPE_VEC4,
        ATTRIBUTE_RENDER_STATIC,
        program, 
        "position"
    );

    vertexArray.color = createVertexAttribute(
        ARRAY_TYPE_FLOAT, 
        VERTEX_ATTRIBUTE_TYPE_VEC4,
        ATTRIBUTE_RENDER_DYNAMIC,
        program, 
        "color"
    );

    vertexArray.model = createVertexAttribute(
        ARRAY_TYPE_FLOAT,
        VERTEX_ATTRIBUTE_TYPE_MAT4,
        ATTRIBUTE_RENDER_DYNAMIC,
        program,
        "model"
    );

    vertexArray.indices = createArray(ARRAY_TYPE_INT);

    vertexArray.vao[0] = -1;
    vertexArray.ebo[0] = -1;

    createVAO(&vertexArray);

    return vertexArray;
}

/* ******************************************************************************** */

none destroyVertexArray(struct vertexArray *vertexArray){
    destroyVertexAttribute(&vertexArray->position);
    destroyVertexAttribute(&vertexArray->color);
    destroyVertexAttribute(&vertexArray->model);

    destroyArray(&vertexArray->indices);

    vertexArray->vao[0] = -1;
    vertexArray->ebo[0] = -1;
}

/* ******************************************************************************** */

none prepareVertexArray(struct vertexArray *array){
    bindVAO(array);

    setupBuffer(&array->position);
    setupBuffer(&array->color);
    setupBuffer(&array->model);

    fillElementBuffer(array);

    unbindVAO();
}
/* ******************************************************************************** */

none renderVertexArray(struct vertexArray *array){
    bindVAO(array);

    glDrawElements(
        array->renderType, 
        array->indices.size, 
        GL_UNSIGNED_INT, 
        NULL
    );

    unbindVAO();
}

/* ******************************************************************************** */

none renderVertexArrayInstanced(struct vertexArray *array, i32 count){
    glDrawElementsInstanced(
        array->renderType, 
        array->indices.size, 
        GL_UNSIGNED_INT, 
        NULL,
        count
    );
}

/* ******************************************************************************** */

none fillElementBuffer(struct vertexArray *array){
    glGenBuffers(1, array->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, array->ebo[0]);

    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        byteSize(&array->indices),
        getBytes(&array->indices),
        GL_DYNAMIC_DRAW
    );
}

/* ******************************************************************************** */

none createVAO(struct vertexArray *array){
    glGenVertexArrays(1, array->vao);
}

/* ******************************************************************************** */

none bindVAO(struct vertexArray *array){
    glBindVertexArray(array->vao[0]);
}

/* ******************************************************************************** */

none unbindVAO(){
    glBindVertexArray(0);
}

/* ******************************************************************************** */