/* ******************************************************************************** */

#include "mat4.h"

/* ******************************************************************************** */

struct mat4 translate(struct mat4 inputMat, struct vec4 vec){
    assert(vec.x || vec.y || vec.z);

    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.field[3][0] += vec.x;
    translationMatrix.field[3][1] += vec.y;
    translationMatrix.field[3][2] += vec.z;
    translationMatrix.field[3][3] = 1.0f;

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 scale(struct mat4 inputMat, f32 factor){
    assert(factor > 0.0 && factor <= 2.0);

    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.field[0][0] *= factor;
    translationMatrix.field[1][1] *= factor;
    translationMatrix.field[2][2] *= factor;

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 rotateX(struct mat4 inputMat, f32 angle){
    assert(angle >= -360.0 && angle <= 360.0);

    f32 angleRad = angle*M_PI/180;

    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.field[1][1] = cos(angleRad);
    translationMatrix.field[1][2] = -sin(angleRad);

    translationMatrix.field[2][1] = sin(angleRad);
    translationMatrix.field[2][2] = cos(angleRad);

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 rotateY(struct mat4 inputMat, f32 angle){
    assert(angle >= -360.0 && angle <= 360.0);

    f32 angleRad = angle*M_PI/180;

    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.field[0][0] = cos(angleRad);
    translationMatrix.field[0][2] = sin(angleRad);

    translationMatrix.field[2][0] = -sin(angleRad);
    translationMatrix.field[2][2] = cos(angleRad);

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 rotateZ(struct mat4 inputMat, f32 angle){
    assert(angle >= -360.0 && angle <= 360.0);

    f32 angleRad = angle*M_PI/180;

    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.field[0][0] = cos(angleRad);
    translationMatrix.field[0][1] = sin(angleRad);

    translationMatrix.field[1][0] = -sin(angleRad);
    translationMatrix.field[1][1] = cos(angleRad);

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 reflectX(struct mat4 inputMat){
    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.field[0][0] = -1;

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */

struct mat4 reflectY(struct mat4 inputMat){
    struct mat4 translationMatrix = identityMatrix();

    translationMatrix.field[1][1] = -1;

    return mulMat4(inputMat, translationMatrix);
}

/* ******************************************************************************** */