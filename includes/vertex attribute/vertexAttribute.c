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
            result.value.mat4 = identityMat4();
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
            return (f32*)&attr->value.mat4.field[0][0];
    }
}

/* ******************************************************************************** */