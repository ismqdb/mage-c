/* ******************************************************************************** */

#include "triangle.h"

/* ******************************************************************************** */

struct triangle createTriangle(struct point _a, struct point _b, struct point _c){
    struct triangle triangle;

    triangle.apt = _a;
    triangle.bpt = _b;
    triangle.cpt = _c;

    triangle.vertices = fcreateArray();
    triangle.indices = icreateArray();

    insertPoint(&triangle.vertices, triangle.apt);
    insertPoint(&triangle.vertices, triangle.bpt);
    insertPoint(&triangle.vertices, triangle.cpt);

    insertIndice(&triangle.indices, 0);
    insertIndice(&triangle.indices, 1);
    insertIndice(&triangle.indices, 2);

    return triangle;
}

/* ******************************************************************************** */