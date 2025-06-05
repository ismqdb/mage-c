/* ******************************************************************************** */

#include "circle.h"

/* ******************************************************************************** */

struct circle createCircle(struct vec4 _pos, float _rad, int noOfTri){
    assert(_rad > 0);
    assert(noOfTri > 4);

    struct circle circle;

    circle.vertices = createArray(ARRAY_FLOAT);
    circle.indices = createArray(ARRAY_INT);

    circle.position = _pos;
    circle.radius = _rad;
    circle.noOfTriangles = noOfTri;
    circle.arcLen = 360.0/noOfTri;

    struct vec4 temp;
    float angle = 0.0;
    float angleRad = 0.0;

    temp.x = _pos.x;
    temp.y = _pos.y;
    temp.z = 0.0;
    temp.w = 1.0;

    insertVec4(&circle.vertices, &temp);

    for(int i = 0; i < (noOfTri*2); i++){
        angleRad = (angle * 3.14)/360;

        temp.x = _pos.x + _rad * cos(angleRad);
        temp.y = _pos.y + _rad * sin(angleRad);

        insertVec4(&circle.vertices, &temp);

        angle += circle.arcLen;
    }

    int i = 0;

    for(; i < noOfTri*2; i++){
        insertInt(&circle.indices, 0);
        insertInt(&circle.indices, i);
        insertInt(&circle.indices, i+1);
    }

    insertInt(&circle.indices, 0);
    insertInt(&circle.indices, i);
    insertInt(&circle.indices, 1);

    return circle;
}

/* ******************************************************************************** */