/* ******************************************************************************** */

#include "triangle.h"

/* ******************************************************************************** */

struct triangle createTriangle(struct point _a, struct point _b, struct point _c){
    struct triangle triangle;

    triangle.apt = _a;
    triangle.bpt = _b;
    triangle.cpt = _c;

    triangle.vertices = vcreateArray();
    triangle.indices = icreateArray();

    insertPoint(&triangle.vertices, triangle.apt);
    insertPoint(&triangle.vertices, triangle.bpt);
    insertPoint(&triangle.vertices, triangle.cpt);

    insertInt(&triangle.indices, 0);
    insertInt(&triangle.indices, 1);
    insertInt(&triangle.indices, 2);

    return triangle;
}

/* ******************************************************************************** */