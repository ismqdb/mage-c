/* ******************************************************************************** */

#include "./vertexArray.h"

/* ******************************************************************************** */

struct vertexArray createVertexArray(enum arrayRenderType type, i32 program){
    assert(type > ARRAY_RENDER_TYPE_MIN && type < ARRAY_RENDER_TYPE_MAX);

    struct vertexArray vertexArray;

    vertexArray.renderType  = type;
    vertexArray.program     = program;

    vertexArray.vertices    = createVertexAttribute(ARRAY_TYPE_FLOAT, program, "position");
    vertexArray.colors      = createVertexAttribute(ARRAY_TYPE_FLOAT, program, "color");

    vertexArray.indices     = createArray(ARRAY_TYPE_INT);

    vertexArray.vao[0] = -1;
    vertexArray.vbo[0] = -1;
    vertexArray.ebo[0] = -1;

    return vertexArray;
}

/* ******************************************************************************** */

none destroyVertexArray(struct vertexArray *vertexArray){
    destroyVertexAttribute(&vertexArray->vertices);
    destroyVertexAttribute(&vertexArray->colors);

    destroyArray(&vertexArray->indices);

    vertexArray->vao[0] = -1;
    vertexArray->vbo[0] = -1;
    vertexArray->ebo[0] = -1;
}

/* ******************************************************************************** */

none prepareVertexArray(struct vertexArray *array){
    glGenVertexArrays(1, array->vao);
    glBindVertexArray(array->vao[0]);

    glGenBuffers(1, array->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, array->vbo[0]);

    glBufferData(
        GL_ARRAY_BUFFER,
        sizeofAttr(&array->vertices) + sizeofAttr(&array->colors),
        NULL,
        GL_DYNAMIC_DRAW
    );

    glBufferSubData(
        GL_ARRAY_BUFFER,
        0,
        sizeofAttr(&array->vertices),
        rawElements(&array->vertices)
    );

    glBufferSubData(
        GL_ARRAY_BUFFER,
        sizeofAttr(&array->vertices),
        sizeofAttr(&array->colors),
        rawElements(&array->colors)
    );

    glVertexAttribPointer(
        0, 
        4, 
        GL_FLOAT, 
        GL_FALSE, 
        0, 
        NULL
    );
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(
        1, 
        4, 
        GL_FLOAT, 
        GL_FALSE, 
        0, 
        (const none*)sizeofAttr(&array->colors)
    );
    glEnableVertexAttribArray(1);

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

none renderVertexArray(struct vertexArray *array){
    glDrawElements(
        array->renderType, 
        array->indices.size, 
        GL_UNSIGNED_INT, 
        NULL
    );
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