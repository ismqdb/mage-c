/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../point/point.h"

#include "../varray/varray.h"
#include "../iarray/iarray.h"

/* ******************************************************************************** */

struct triangle createTriangle(struct point, struct point, struct point);

/* ******************************************************************************** */

struct triangle {
    struct point apt;
    struct point bpt;
    struct point cpt;

    struct varray vertices;
    struct iarray indices;
};

/* ******************************************************************************** */