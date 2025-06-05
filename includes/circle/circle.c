/* ******************************************************************************** */

#include "circle.h"

/* ******************************************************************************** */

struct circle createCircle(struct vec4 _pos, float _rad, int noOfTri){
    assert(_rad > 0);
    assert(noOfTri > 4);

    struct circle circle;

    circle.position = _pos;
    circle.radius = _rad;
    circle.noOfTriangles = noOfTri;
    circle.arcLen = 360.0/noOfTri;

    struct array pointArray;

    

    return circle;
}

/* ******************************************************************************** */