/* ******************************************************************************** */

#include "mat4.h"

/* ******************************************************************************** */

struct mat4 translate(struct mat4 inputMat, f32 tx, f32 ty, f32 tz){
    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.elems[3][0] += tx;
    translationMatrix.elems[3][1] += ty;
    translationMatrix.elems[3][2] += tz;
    translationMatrix.elems[3][3] = 1.0f;

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 scale(struct mat4 inputMat, f32 factor){
    assert(factor > 0.0 && factor <= 2.0);

    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.elems[0][0] *= factor;
    translationMatrix.elems[1][1] *= factor;
    translationMatrix.elems[2][2] *= factor;

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 rotateX(struct mat4 inputMat, f32 angle){
    assert(angle >= -360.0 && angle <= 360.0);

    f32 angleRad = angle*M_PI/180;

    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.elems[1][1] = cos(angleRad);
    translationMatrix.elems[1][2] = -sin(angleRad);

    translationMatrix.elems[2][1] = sin(angleRad);
    translationMatrix.elems[2][2] = cos(angleRad);

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 rotateY(struct mat4 inputMat, f32 angle){
    assert(angle >= -360.0 && angle <= 360.0);

    f32 angleRad = angle*M_PI/180;

    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.elems[0][0] = cos(angleRad);
    translationMatrix.elems[0][2] = sin(angleRad);

    translationMatrix.elems[2][0] = -sin(angleRad);
    translationMatrix.elems[2][2] = cos(angleRad);

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 rotateZ(struct mat4 inputMat, f32 angle){
    assert(angle >= -360.0 && angle <= 360.0);

    f32 angleRad = angle*M_PI/180;

    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.elems[0][0] = cos(angleRad);
    translationMatrix.elems[0][1] = sin(angleRad);

    translationMatrix.elems[1][0] = -sin(angleRad);
    translationMatrix.elems[1][1] = cos(angleRad);

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 reflectX(struct mat4 inputMat){
    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.elems[0][0] = -1;

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 reflectY(struct mat4 inputMat){
    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.elems[1][1] = -1;

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */