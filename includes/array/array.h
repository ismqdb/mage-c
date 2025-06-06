/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* ******************************************************************************** */

#include "../allocMacros.h"
#include "../triangle/triangle.h"

/* ******************************************************************************** */

enum arrayType {
    ARRAY_TYPE_MIN,

    ARRAY_INT,
    ARRAY_FLOAT,

    ARRAY_TYPE_MAX
};

/* ******************************************************************************** */

struct array {
    enum arrayType type;

    union {
        int     *ints;
        float   *floats;
    } data;

    int size;
    int capacity;
};

/* ******************************************************************************** */

struct array createArray(enum arrayType);
void destroyArray(struct array*);

/* ******************************************************************************** */

void reserve(struct array*);

/* ******************************************************************************** */

void* getBytes(struct array*);
int byteSize(struct array*);

/* ******************************************************************************** */

int insertInt(struct array*, int);
void insertFloat(struct array*, float);

/* ******************************************************************************** */

void insertPoint(struct array*, struct point);
void insertIndice(struct array*, int);

/* ******************************************************************************** */

void insertTriangle(struct array*, struct triangle);

/* ******************************************************************************** */