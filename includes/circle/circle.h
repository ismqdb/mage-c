/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../vec4/vec4.h"

#include "../point/point.h"
#include "../triangle/triangle.h"

#include "../varray/varray.h"
#include "../iarray/iarray.h"

/* ******************************************************************************** */

#include <assert.h>
#include <math.h>

/* ******************************************************************************** */

struct circle createCircle(struct vec4, float, int);

/* ******************************************************************************** */

struct circle {
    float radius;
    float arcLen;
    unsigned noOfTriangles;
    struct vec4 position;

    struct varray vertices;
    struct iarray indices;
};

/* ******************************************************************************** */