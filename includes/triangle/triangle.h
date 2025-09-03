/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../point/point.h"

#include "../array/array.h"

/* ******************************************************************************** */

struct triangle createTriangle(struct point, struct point, struct point);

/* ******************************************************************************** */

struct triangle {
    struct point apt;
    struct point bpt;
    struct point cpt;

    struct array vertices;
    struct array indices;
};

/* ******************************************************************************** */