/* ******************************************************************************** */

#include "mat4.h"

/* ******************************************************************************** */

struct mat4 translateMat4(struct mat4 inputMat, struct vec4 vec){
    assert(vec.x || vec.y || vec.z);

    struct mat4 translationMatrix = identityMat4();

    translationMatrix.field[3][0] += vec.x;
    translationMatrix.field[3][1] += vec.y;
    translationMatrix.field[3][2] += vec.z;
    translationMatrix.field[3][3] = 1.0f;

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 scaleMat4(struct mat4 inputMat, f32 factor){
    assert(factor > 0.0 && factor <= 2.0);

    struct mat4 translationMatrix = identityMat4();

    translationMatrix.field[0][0] *= factor;
    translationMatrix.field[1][1] *= factor;
    translationMatrix.field[2][2] *= factor;

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 xrotateMat4(struct mat4 inputMat, f32 angle){
    assert(angle >= -360.0 && angle <= 360.0);

    f32 angleRad = angle*M_PI/180;

    struct mat4 translationMatrix = identityMat4();

    translationMatrix.field[1][1] = cos(angleRad);
    translationMatrix.field[1][2] = -sin(angleRad);

    translationMatrix.field[2][1] = sin(angleRad);
    translationMatrix.field[2][2] = cos(angleRad);

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 yrotateMat4(struct mat4 inputMat, f32 angle){
    assert(angle >= -360.0 && angle <= 360.0);

    f32 angleRad = angle*M_PI/180;

    struct mat4 translationMatrix = identityMat4();

    translationMatrix.field[0][0] = cos(angleRad);
    translationMatrix.field[0][2] = sin(angleRad);

    translationMatrix.field[2][0] = -sin(angleRad);
    translationMatrix.field[2][2] = cos(angleRad);

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 zrotateMat4(struct mat4 inputMat, f32 angle){
    assert(angle >= -360.0 && angle <= 360.0);

    f32 angleRad = angle*M_PI/180;

    struct mat4 translationMatrix = identityMat4();

    translationMatrix.field[0][0] = cos(angleRad);
    translationMatrix.field[0][1] = sin(angleRad);

    translationMatrix.field[1][0] = -sin(angleRad);
    translationMatrix.field[1][1] = cos(angleRad);

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 xreflectMat4(struct mat4 inputMat){
    struct mat4 translationMatrix = identityMat4();

    translationMatrix.field[0][0] = -1;

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 yreflectMat4(struct mat4 inputMat){
    struct mat4 translationMatrix = identityMat4();

    translationMatrix.field[1][1] = -1;

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */