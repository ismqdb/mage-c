/* ******************************************************************************** */

#include "circle.h"

/* ******************************************************************************** */

struct circle createCircle(struct vec4 _pos, f32 _rad, i32 noOfTri){
    assert(_rad > 0.0 && _rad < 1.0);
    assert(noOfTri >= 4 && noOfTri <= 32);

    struct circle circle;

    circle.vertices = createArray(ARRAY_TYPE_FLOAT);
    circle.indices  = createArray(ARRAY_TYPE_INT);

    circle.position = _pos;
    circle.radius = _rad;
    circle.noOfTriangles = noOfTri;
    circle.arcLen = 360.0/noOfTri;

    struct point centerPoint = createPoint(_pos.x, _pos.y, 0.0, 1.0);
    insertVec4(&circle.vertices, centerPoint.position);

    struct point pt2;
    struct point pt3;

    f32 angle = 0.0;
    f32 angleRad = 0.0;

    for(i32 i = 0; i < noOfTri; i++){
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

        insertVec4(&circle.vertices, pt2.position);
        insertVec4(&circle.vertices, pt3.position);

        angle += circle.arcLen;
    }

    for(i32 i = 1; i < (noOfTri*2); i++){
        insertIndice(&circle.indices, 0);
        insertIndice(&circle.indices, i);
        insertIndice(&circle.indices, i + 1);
    }

    insertIndice(&circle.indices, 0);
    insertIndice(&circle.indices, noOfTri*2);
    insertIndice(&circle.indices, 1);

    return circle;
}

/* ******************************************************************************** */