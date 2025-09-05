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
        program, 
        "position"
    );

    vertexArray.color = createVertexAttribute(
        ARRAY_TYPE_FLOAT, 
        VERTEX_ATTRIBUTE_TYPE_VEC4,
        program, 
        "color"
    );

    vertexArray.model = createVertexAttribute(
        ARRAY_TYPE_FLOAT,
        VERTEX_ATTRIBUTE_TYPE_MAT4,
        program,
        "model"
    );

    vertexArray.indices = createArray(ARRAY_TYPE_INT);

    vertexArray.vao[0] = -1;
    vertexArray.vbo[0] = -1;
    vertexArray.ebo[0] = -1;

    return vertexArray;
}

/* ******************************************************************************** */

none destroyVertexArray(struct vertexArray *vertexArray){
    destroyVertexAttribute(&vertexArray->position);
    destroyVertexAttribute(&vertexArray->color);

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
        sizeofAttribute(&array->position) + sizeofAttribute(&array->color),
        NULL,
        GL_DYNAMIC_DRAW
    );

    glBufferSubData(
        GL_ARRAY_BUFFER, 
        0,
        sizeofAttribute(&array->position),
        rawElements(&array->position)
    );

    glBufferSubData(
        GL_ARRAY_BUFFER,
        sizeofAttribute(&array->position),
        sizeofAttribute(&array->color),
        rawElements(&array->color)
    );

    glVertexAttribPointer(
        0, 
        4, 
        GL_FLOAT, 
        GL_FALSE, 
        0, 
        NULL
    );
    glEnableVertexAttribArray(array->position.position);

    glVertexAttribPointer(
        1, 
        4, 
        GL_FLOAT, 
        GL_FALSE, 
        0, 
        (const none*)sizeofAttribute(&array->color)
    );
    glEnableVertexAttribArray(array->color.position);

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