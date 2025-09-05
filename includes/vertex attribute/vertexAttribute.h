/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../types.h"

/* ******************************************************************************** */

#include "../array/array.h"
#include "../mat4/mat4.h"

/* ******************************************************************************** */

#include "vertexAttributeType.h"

/* ******************************************************************************** */

struct vertexAttribute createVertexAttribute(
    enum arrayType, enum vertexAttributeType, i32, u8*
);

/* ******************************************************************************** */

none destroyVertexAttribute(struct vertexAttribute*);

/* ******************************************************************************** */

i32 sizeofAttribute(struct vertexAttribute*);

/* ******************************************************************************** */

i32 countElements(struct vertexAttribute*);

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
    
    union {
        struct array array;
        struct {
            struct array marray;
            struct mat4 mat;
            i32 row1;
            i32 row2;
            i32 row3;
            i32 row4;
        } mat4;
    } value;

    i32 buffer;

    i32 program;
    i32 position;
    u8 *name;
};

/* ******************************************************************************** */