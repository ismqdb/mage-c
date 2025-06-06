/* ******************************************************************************** */

#include "triangle.h"

/* ******************************************************************************** */

struct triangle createTriangle(struct point _a, struct point _b, struct point _c){
    struct triangle triangle;

    triangle.point_a = _a;
    triangle.point_b = _b;
    triangle.point_c = _c;

    return triangle;
}

/* ******************************************************************************** */