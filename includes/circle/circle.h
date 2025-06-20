/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../types.h"

#include "../vec4/vec4.h"

#include "../point/point.h"
#include "../triangle/triangle.h"

#include "../varray/varray.h"
#include "../iarray/iarray.h"

/* ******************************************************************************** */

#include <assert.h>
#include <math.h>

/* ******************************************************************************** */

struct circle createCircle(struct vec4, f32, i32);

/* ******************************************************************************** */

struct circle {
    f32 radius;
    f32 arcLen;
    u32 noOfTriangles;
    struct vec4 position;

    struct varray vertices;
    struct iarray indices;
};

/* ******************************************************************************** */