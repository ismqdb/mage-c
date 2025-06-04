/* ******************************************************************************** */

#include "triangle.h"

/* ******************************************************************************** */

struct triangle1 createTriangle(struct point _a, struct point _b, struct point _c){
    struct triangle1 triangle;

    triangle.point_a = _a;
    triangle.point_b = _b;
    triangle.point_c = _c;

    return triangle;
}

/* ******************************************************************************** */