/* ******************************************************************************** */

#include "mat4.h"

/* ******************************************************************************** */

struct mat4 zeroMatrix(){
    struct mat4 result;

    result.a00 = 0;
    result.a01 = 0;
    result.a02 = 0;
    result.a03 = 0;

    result.a10 = 0;
    result.a11 = 0;
    result.a12 = 0;
    result.a13 = 0;

    result.a20 = 0;
    result.a21 = 0;
    result.a22 = 0;
    result.a23 = 0;

    result.a30 = 0;
    result.a31 = 0;
    result.a32 = 0;
    result.a33 = 0;

    return result;
}

/* ******************************************************************************** */

struct mat4 identityMatrix(){
    struct mat4 result;

    result.a00 = 1;
    result.a01 = 0;
    result.a02 = 0;
    result.a03 = 0;

    result.a10 = 0;
    result.a11 = 1;
    result.a12 = 0;
    result.a13 = 0;

    result.a20 = 0;
    result.a21 = 0;
    result.a22 = 1;
    result.a23 = 0;

    result.a30 = 0;
    result.a31 = 0;
    result.a32 = 0;
    result.a33 = 1;

    return result;
}

/* ******************************************************************************** */

struct mat4 translationMatrix(struct mat4 inputMat, struct vec4 vec){
    inputMat.a03 = vec.x;
    inputMat.a13 = vec.y;
    inputMat.a23 = vec.z;
    inputMat.a33 = 1.0;

    return inputMat;
}

/* ******************************************************************************** */

struct mat4 scalingMatrix(struct mat4 inputMat, float xScale, float yScale){
    assert(xScale > 0.0 && xScale <= 2.0);
    assert(yScale > 0.0 && yScale <= 2.0);

    inputMat.a00 = xScale;
    inputMat.a11 = yScale;

    return inputMat;
}

/* ******************************************************************************** */

struct mat4 rotationMatrix(struct mat4 inputMat, float xangle, float yangle, float zangle){
    assert(xangle >= -360.0 && xangle <= 360.0);
    assert(yangle >= -360.0 && yangle <= 360.0);
    assert(zangle >= -360.0 && zangle <= 360.0);

    inputMat.a00 = cos(yangle)*cos(zangle);
    inputMat.a01 = cos(yangle)*sin(zangle);
    inputMat.a02 = -sin(yangle);

    inputMat.a10 = sin(xangle)*sin(yangle)*cos(zangle) - cos(xangle)*sin(zangle);
    inputMat.a11 = sin(xangle)*sin(yangle)*sin(zangle) + cos(xangle)*cos(zangle);
    inputMat.a12 = sin(xangle)*cos(yangle);

    inputMat.a20 = cos(xangle)*sin(yangle)*cos(zangle) + sin(xangle)*sin(zangle);
    inputMat.a21 = cos(xangle)*sin(yangle)*sin(zangle) - sin(xangle)*cos(zangle);
    inputMat.a22 = cos(xangle)*cos(yangle);

    return inputMat;
}

/* ******************************************************************************** */

struct mat4 reflectMatrix(struct mat4 inputMat, int xref, int yref){
    assert(xref == 0 || xref == 1);
    assert(yref == 0 || yref == 1);

    if(xref)
        inputMat.a11 = -1;

    if(yref)
        inputMat.a00 = -1;

    return inputMat;
}

/* ******************************************************************************** */