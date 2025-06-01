/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* ******************************************************************************** */

#include "../allocMacros.h"
#include "../vec4/vec4.h"

/* ******************************************************************************** */

enum arrayType {
    ARRAY_TYPE_MIN,

    ARRAY_INT,
    ARRAY_DOUBLE,

    ARRAY_TYPE_MAX
};

/* ******************************************************************************** */

struct array {
    enum arrayType type;

    union {
        int     *ints;
        double  *doubles;
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
void insertDouble(struct array*, double);

/* ******************************************************************************** */