/* ******************************************************************************** */

#include "circle.h"

/* ******************************************************************************** */

struct circle createCircle(struct vec4 _pos, float _rad, int noOfTri){
    assert(_rad > 0.0 && _rad < 1.0);
    assert(noOfTri >= 4 && noOfTri <= 32);

    struct circle circle;

    circle.vertices = vcreateArray();
    circle.indices = icreateArray();

    circle.position = _pos;
    circle.radius = _rad;
    circle.noOfTriangles = noOfTri;
    circle.arcLen = 360.0/noOfTri;

    struct point centerPoint = createPoint(_pos.x, _pos.y, 0.0, 1.0);
    insertPoint(&circle.vertices, centerPoint);

    struct point pt2;
    struct point pt3;

    float angle = 0.0;
    float angleRad = 0.0;

    for(int i = 0; i < noOfTri; i++){
        angleRad = (angle * 3.14)/360;

        pt2 = createPoint(
            _pos.x + _rad * cos(angleRad),
            _pos.y + _rad * sin(angleRad),
            0.0,
            1.0
        );

        angle += circle.arcLen;
        angleRad = (angle * 3.14)/360;

        pt3 = createPoint(
            _pos.x + _rad * cos(angleRad),
            _pos.y + _rad * sin(angleRad),
            0.0,
            1.0
        );

        insertPoint(&circle.vertices, pt2);
        insertPoint(&circle.vertices, pt3);

        angle += circle.arcLen;
    }

    for(int i = 1; i < (noOfTri*2); i++){
        insertInt(&circle.indices, 0);
        insertInt(&circle.indices, i);
        insertInt(&circle.indices, i + 1);
    }

    insertInt(&circle.indices, 0);
    insertInt(&circle.indices, noOfTri*2);
    insertInt(&circle.indices, 1);

    return circle;
}

/* ******************************************************************************** */