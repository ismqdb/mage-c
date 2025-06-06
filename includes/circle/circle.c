/* ******************************************************************************** */

#include "circle.h"

/* ******************************************************************************** */

struct circle createCircle(struct vec4 _pos, float _rad, int noOfTri){
    assert(_rad > 0 && _rad < 1.0);
    assert(noOfTri > 4);

    struct circle circle;

    circle.vertices = createArray(ARRAY_FLOAT);
    circle.indices = createArray(ARRAY_INT);

    circle.position = _pos;
    circle.radius = _rad;
    circle.noOfTriangles = noOfTri;
    circle.arcLen = 360.0/noOfTri;

    struct point centerPoint = createPoint(_pos.x, _pos.y, 0.0, 1.0);

    struct point pt2;
    struct point pt3;

    float angle = 0.0;
    float angleRad = 0.0;

    for(int i = 0; i < (noOfTri*2); i++){
        angleRad = (angle * 3.14)/360;

        pt2 = createPoint(
            _pos.x + _rad * cos(angleRad),
            _pos.x + _rad * sin(angleRad),
            0.0,
            1.0
        );

        angle += circle.arcLen;

        pt3 = createPoint(
            _pos.x + _rad * cos(angleRad),
            _pos.x + _rad * sin(angleRad),
            0.0,
            1.0
        );

        struct triangle _tempTri = createTriangle(centerPoint, pt2, pt3);

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