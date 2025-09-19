/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../types.h"

/* ******************************************************************************** */

#include "../array/array.h"
#include "../mat4/mat4.h"

/* ******************************************************************************** */

#include "vertexAttributeType.h"
#include "attributeRenderType.h"

/* ******************************************************************************** */

struct vertexAttribute createVertexAttribute(
    enum arrayType, 
    enum vertexAttributeType, 
    enum attributeRenderType,
    i32, 
    u8*
);

/* ******************************************************************************** */

none destroyVertexAttribute(struct vertexAttribute*);

/* ******************************************************************************** */

i32 sizeofAttribute(struct vertexAttribute*);

/* ******************************************************************************** */

f32* rawElements(struct vertexAttribute*);

/* ******************************************************************************** */

none createBuffer(struct vertexAttribute*);

/* ******************************************************************************** */

none bindBuffer(struct vertexAttribute*);

/* ******************************************************************************** */

none unbindBuffer();

/* ******************************************************************************** */

none fillBuffer(struct vertexAttribute*);

/* ******************************************************************************** */

none layoutBuffer(struct vertexAttribute*);

/* ******************************************************************************** */

none enableBuffer(struct vertexAttribute*);

/* ******************************************************************************** */

none setupBuffer(struct vertexAttribute*);

/* ******************************************************************************** */

struct vertexAttribute {
    enum arrayType utype;
    enum vertexAttributeType attrType;
    enum attributeRenderType renderType;
    
    union {
        struct array array;
        struct mat4 mat; 
    } value;

    i32 buffer;

    i32 program;
    i32 position;
    i32 pos[4];
    u8 *name;
};

/* ******************************************************************************** */