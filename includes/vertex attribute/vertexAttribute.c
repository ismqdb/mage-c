/* ******************************************************************************** */

#include "./vertexAttribute.h"

/* ******************************************************************************** */

struct vertexAttr createVertexAttribute(enum arrayType type, i32 program, u8 *name){
    assert(type > ARRAY_TYPE_MIN && type < ARRAY_TYPE_MAX);
    assert(program > -1);

    struct vertexAttr result;

    result.name = name;
    result.position = glGetAttribLocation(program, name);
    result.program = program;
    result.type = type;
    result.value = createArray(type);

    return result;
}

/* ******************************************************************************** */

none destroyVertexAttribute(struct vertexAttr *attr){
    attr->name = "";
    attr->position = -1;
    attr->program = -1;
    attr->type = ARRAY_TYPE_MIN;

    destroyArray(&attr->value);
}

/* ******************************************************************************** */

i32 sizeofAttr(struct vertexAttr *attr){
    return byteSize(&attr->value);
}

/* ******************************************************************************** */

i32 countElements(struct vertexAttr *attr){
    return attr->value.size;
}

/* ******************************************************************************** */

f32* rawElements(struct vertexAttr *attr){
    return (f32*)getBytes(&attr->value);
}

/* ******************************************************************************** */