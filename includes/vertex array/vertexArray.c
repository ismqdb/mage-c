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

none destroyVertexArray(struct vertexArray *vertexArray){
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

none prepareVertexArray(struct vertexArray *array){
    glGenVertexArrays(1, array->vao);
    glBindVertexArray(array->vao[0]);

    glGenBuffers(1, array->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, array->vbo[0]);

    glBufferData(
        GL_ARRAY_BUFFER,
        sizeofVertices(array) + sizeofColors(array),
        NULL,
        GL_DYNAMIC_DRAW
    );

    glBufferSubData(
        GL_ARRAY_BUFFER,
        0,
        sizeofVertices(array),
        rawVertices(array)
    );

    glBufferSubData(
        GL_ARRAY_BUFFER,
        sizeofVertices(array),
        sizeofColors(array),
        rawColors(array)
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
        (const none*)sizeofColors(array)
    );
    glEnableVertexAttribArray(1);

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

none renderVertexArray(struct vertexArray *array){
    glDrawElements(
        array->renderType, 
        countIndices(array), 
        GL_UNSIGNED_INT, 
        NULL
    );
}

/* ******************************************************************************** */

none renderVertexArrayInstanced(struct vertexArray *array, i32 count){
    glDrawElementsInstanced(
        array->renderType, 
        countIndices(array), 
        GL_UNSIGNED_INT, 
        NULL,
        count
    );
}

/* ******************************************************************************** */