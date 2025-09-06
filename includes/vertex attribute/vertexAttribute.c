/* ******************************************************************************** */

#include "./vertexAttribute.h"

/* ******************************************************************************** */

struct vertexAttribute createVertexAttribute(
    enum arrayType type, 
    enum vertexAttributeType attrType,
    i32 program, 
    u8 *name
){
    assert(type > ARRAY_TYPE_MIN && type < ARRAY_TYPE_MAX);
    assert(program > -1);

    struct vertexAttribute result;

    result.name = name;
    result.position = glGetAttribLocation(program, name);
    result.program = program;
    result.utype = type;
    result.attrType = attrType;

    switch(result.attrType){
        case VERTEX_ATTRIBUTE_TYPE_VEC4:
            result.value.array = createArray(type);
            break;

        case VERTEX_ATTRIBUTE_TYPE_MAT4:
            result.value.mat4.mat = identityMat4();

            result.value.mat4.row1 = result.position + 0;
            result.value.mat4.row2 = result.position + 1;
            result.value.mat4.row3 = result.position + 2;
            result.value.mat4.row4 = result.position + 3;
            break;
    }

    return result;
}

/* ******************************************************************************** */

none destroyVertexAttribute(struct vertexAttribute *attr){
    attr->name = "";
    attr->position = -1;
    attr->program = -1;
    attr->utype = ARRAY_TYPE_MIN;

    switch(attr->attrType){
        case VERTEX_ATTRIBUTE_TYPE_VEC4:
            destroyArray(&attr->value.array);
            break;

        case VERTEX_ATTRIBUTE_TYPE_MAT4:
            destroyArray(&attr->value.mat4.marray);
            attr->value.mat4.mat = identityMat4();

            attr->value.mat4.row1 = -1;
            attr->value.mat4.row2 = -1;
            attr->value.mat4.row3 = -1;
            attr->value.mat4.row4 = -1;
            break;
    }
}

/* ******************************************************************************** */

i32 sizeofAttribute(struct vertexAttribute *attr){
    switch(attr->attrType){
        case VERTEX_ATTRIBUTE_TYPE_VEC4:
            return byteSize(&attr->value.array);

        case VERTEX_ATTRIBUTE_TYPE_MAT4:
            attr->value.mat4.marray = mat4ToArray(attr->value.mat4.mat);
            return byteSize(&attr->value.mat4.marray);
    }
}

/* ******************************************************************************** */

i32 countElements(struct vertexAttribute *attr){
    switch(attr->attrType){
        case VERTEX_ATTRIBUTE_TYPE_VEC4:
            return attr->value.array.size;

        case VERTEX_ATTRIBUTE_TYPE_MAT4:
            attr->value.mat4.marray = mat4ToArray(attr->value.mat4.mat);
            return attr->value.mat4.marray.size;
    }
}

/* ******************************************************************************** */

f32* rawElements(struct vertexAttribute *attr){
    switch(attr->attrType){
        case VERTEX_ATTRIBUTE_TYPE_VEC4:
            return (f32*)getBytes(&attr->value.array);

        case VERTEX_ATTRIBUTE_TYPE_MAT4:
            attr->value.mat4.marray = mat4ToArray(attr->value.mat4.mat);
            return (f32*)getBytes(&attr->value.mat4.marray);
    }
}

/* ******************************************************************************** */

none createBuffer(struct vertexAttribute *attr){
    glGenBuffers(1, &attr->buffer);
}

/* ******************************************************************************** */

none bindBuffer(struct vertexAttribute *attr){
    glBindBuffer(GL_ARRAY_BUFFER, attr->buffer);
}

/* ******************************************************************************** */

none unbindBuffer(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/* ******************************************************************************** */

none fillBuffer(struct vertexAttribute *attr){
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeofAttribute(attr),
        rawElements(attr),
        GL_DYNAMIC_DRAW
    );
}

/* ******************************************************************************** */

none layoutBuffer(struct vertexAttribute *attr){
    switch(attr->attrType){
        case VERTEX_ATTRIBUTE_TYPE_VEC4:
            glVertexAttribPointer(
                attr->position, 
                4, 
                GL_FLOAT, 
                GL_FALSE, 
                0, 
                NULL
            );
            return;

        case VERTEX_ATTRIBUTE_TYPE_MAT4:
            glVertexAttribPointer(attr->value.mat4.row1, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4 * 4, (void*)(0));
            glVertexAttribPointer(attr->value.mat4.row2, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4 * 4, (void*)(sizeof(float) * 4));
            glVertexAttribPointer(attr->value.mat4.row3, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4 * 4, (void*)(sizeof(float) * 8));
            glVertexAttribPointer(attr->value.mat4.row4, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4 * 4, (void*)(sizeof(float) * 12));

            glVertexAttribDivisor(attr->value.mat4.row1, 1);
            glVertexAttribDivisor(attr->value.mat4.row2, 1);
            glVertexAttribDivisor(attr->value.mat4.row3, 1);
            glVertexAttribDivisor(attr->value.mat4.row4, 1);
            return;
    }
}

/* ******************************************************************************** */

none enableBuffer(struct vertexAttribute *attr){
    switch(attr->attrType){
        case VERTEX_ATTRIBUTE_TYPE_VEC4:
            glEnableVertexAttribArray(attr->position);
            return;

        case VERTEX_ATTRIBUTE_TYPE_MAT4:
            glEnableVertexAttribArray(attr->position);

            glEnableVertexAttribArray(attr->value.mat4.row1);
            glEnableVertexAttribArray(attr->value.mat4.row2);
            glEnableVertexAttribArray(attr->value.mat4.row3);
            glEnableVertexAttribArray(attr->value.mat4.row4);
            return;
    }
}

/* ******************************************************************************** */

none setupBuffer(struct vertexAttribute *attr){
    createBuffer(attr);
    bindBuffer(attr);
    fillBuffer(attr);
    layoutBuffer(attr);
    enableBuffer(attr);
    unbindBuffer();
}

/* ******************************************************************************** */