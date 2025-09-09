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

            for(i32 i = 0; i < 4; i++)
                result.value.mat4.pos[i] = result.position + i;

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
            attr->value.mat4.mat = identityMat4();

            for(i32 i = 0; i < 4; i++)
                attr->value.mat4.pos[i] = -1;

            break;
    }
}

/* ******************************************************************************** */

i32 sizeofAttribute(struct vertexAttribute *attr){
    switch(attr->attrType){
        case VERTEX_ATTRIBUTE_TYPE_VEC4:
            return byteSize(&attr->value.array);

        case VERTEX_ATTRIBUTE_TYPE_MAT4:
            return sizeof(struct mat4);
    }
}

/* ******************************************************************************** */

i32 countElements(struct vertexAttribute *attr){
    switch(attr->attrType){
        case VERTEX_ATTRIBUTE_TYPE_VEC4:
            return attr->value.array.size;

        case VERTEX_ATTRIBUTE_TYPE_MAT4:
            return 16;
    }
}

/* ******************************************************************************** */

f32* rawElements(struct vertexAttribute *attr){
    switch(attr->attrType){
        case VERTEX_ATTRIBUTE_TYPE_VEC4:
            return (f32*)getBytes(&attr->value.array);

        case VERTEX_ATTRIBUTE_TYPE_MAT4:
            return (f32*)&attr->value.mat4.mat.field[0][0];
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
            glVertexAttribPointer(
                attr->value.mat4.pos[0], 
                4, 
                GL_FLOAT, 
                GL_FALSE, 
                sizeof(f32)*4*4, 
                (none*)(0)
            );

            glVertexAttribPointer(
                attr->value.mat4.pos[1], 
                4, 
                GL_FLOAT, 
                GL_FALSE, 
                sizeof(f32)*4*4, 
                (none*)(sizeof(f32) * 4)
            );
            
            glVertexAttribPointer(
                attr->value.mat4.pos[2], 
                4, 
                GL_FLOAT, 
                GL_FALSE, 
                sizeof(f32)*4*4, 
                (none*)(sizeof(f32) * 8)
            );
            
            glVertexAttribPointer(
                attr->value.mat4.pos[3], 
                4, 
                GL_FLOAT, 
                GL_FALSE, 
                sizeof(f32)*4*4, 
                (none*)(sizeof(f32) * 12)
            );

            for(i32 i = 0; i < 4; i++)
                glVertexAttribDivisor(attr->value.mat4.pos[i], 1);

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

            for(i32 i = 0; i < 4; i++)
                glEnableVertexAttribArray(attr->value.mat4.pos[i]);

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