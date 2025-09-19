/* ******************************************************************************** */

#include "triangle.h"

/* ******************************************************************************** */

struct triangle createTriangle(struct point _a, struct point _b, struct point _c){
    struct triangle triangle;

    triangle.apt = _a;
    triangle.bpt = _b;
    triangle.cpt = _c;

    triangle.vertices   = arrayCreate(ARRAY_TYPE_FLOAT);
    triangle.indices    = arrayCreate(ARRAY_TYPE_INT);

    arrayInsert_vec4(&triangle.vertices, triangle.apt.position);
    arrayInsert_vec4(&triangle.vertices, triangle.bpt.position);
    arrayInsert_vec4(&triangle.vertices, triangle.cpt.position);

    arrayInsert_i32(&triangle.indices, 0);
    arrayInsert_i32(&triangle.indices, 1);
    arrayInsert_i32(&triangle.indices, 2);

    return triangle;
}

/* ******************************************************************************** */