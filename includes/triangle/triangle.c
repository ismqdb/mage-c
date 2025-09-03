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

    insertVec4(&triangle.vertices, triangle.apt.position);
    insertVec4(&triangle.vertices, triangle.bpt.position);
    insertVec4(&triangle.vertices, triangle.cpt.position);

    insertIndice(&triangle.indices, 0);
    insertIndice(&triangle.indices, 1);
    insertIndice(&triangle.indices, 2);

    return triangle;
}

/* ******************************************************************************** */