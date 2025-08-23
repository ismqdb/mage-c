/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../point/point.h"

#include "../farray/farray.h"
#include "../iarray/iarray.h"

/* ******************************************************************************** */

struct triangle createTriangle(struct point, struct point, struct point);

/* ******************************************************************************** */

struct triangle {
    struct point apt;
    struct point bpt;
    struct point cpt;

    struct farray vertices;
    struct iarray indices;
};

/* ******************************************************************************** */