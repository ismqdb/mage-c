/* ******************************************************************************** */

#include "triangle.h"

/* ******************************************************************************** */

struct triangle createTriangle(struct point _a, struct point _b, struct point _c){
    struct triangle triangle;

    triangle.apt = _a;
    triangle.bpt = _b;
    triangle.cpt = _c;

    triangle.vertices   = createArray(ARRAY_TYPE_FLOAT);
    triangle.indices    = createArray(ARRAY_TYPE_INT);

    insertvec4(&triangle.vertices, triangle.apt.position);
    insertvec4(&triangle.vertices, triangle.bpt.position);
    insertvec4(&triangle.vertices, triangle.cpt.position);

    inserti32(&triangle.indices, 0);
    inserti32(&triangle.indices, 1);
    inserti32(&triangle.indices, 2);

    return triangle;
}

/* ******************************************************************************** */