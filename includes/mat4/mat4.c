/* ******************************************************************************** */

#include "mat4.h"

/* ******************************************************************************** */

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

/* ******************************************************************************** */

struct mat4 zeroMatrix(){
    struct mat4 result;

    result.elems[0][0] = 0;
    result.elems[0][1] = 0;
    result.elems[0][2] = 0;
    result.elems[0][3] = 0;

    result.elems[1][0] = 0;
    result.elems[1][1] = 0;
    result.elems[1][2] = 0;
    result.elems[1][3] = 0;

    result.elems[2][0] = 0;
    result.elems[2][1] = 0;
    result.elems[2][2] = 0;
    result.elems[2][3] = 0;

    result.elems[3][0] = 0;
    result.elems[3][1] = 0;
    result.elems[3][2] = 0;
    result.elems[3][3] = 0;

    return result;
}

/* ******************************************************************************** */

struct mat4 oneMatrix(){
    struct mat4 result;

    result.elems[0][0] = 1;
    result.elems[0][1] = 1;
    result.elems[0][2] = 1;
    result.elems[0][3] = 1;

    result.elems[1][0] = 1;
    result.elems[1][1] = 1;
    result.elems[1][2] = 1;
    result.elems[1][3] = 1;

    result.elems[2][0] = 1;
    result.elems[2][1] = 1;
    result.elems[2][2] = 1;
    result.elems[2][3] = 1;

    result.elems[3][0] = 1;
    result.elems[3][1] = 1;
    result.elems[3][2] = 1;
    result.elems[3][3] = 1;

    return result;
}

/* ******************************************************************************** */

struct mat4 identityMatrix(){
    struct mat4 result;

    result.elems[0][0] = 1;
    result.elems[0][1] = 0;
    result.elems[0][2] = 0;
    result.elems[0][3] = 0;

    result.elems[1][0] = 0;
    result.elems[1][1] = 1;
    result.elems[1][2] = 0;
    result.elems[1][3] = 0;

    result.elems[2][0] = 0;
    result.elems[2][1] = 0;
    result.elems[2][2] = 1;
    result.elems[2][3] = 0;

    result.elems[3][0] = 0;
    result.elems[3][1] = 0;
    result.elems[3][2] = 0;
    result.elems[3][3] = 1;

    return result;
}

/* ******************************************************************************** */

struct mat4 mulMat4(struct mat4 a, struct mat4 b){
    struct mat4 result = zeroMatrix();

    // Column 0
    result.elems[0][0] 
        = a.elems[0][0]*b.elems[0][0] 
        + a.elems[1][0]*b.elems[0][1] 
        + a.elems[2][0]*b.elems[0][2] 
        + a.elems[3][0]*b.elems[0][3];

    result.elems[0][1] 
        = a.elems[0][1]*b.elems[0][0]
        + a.elems[1][1]*b.elems[0][1]
        + a.elems[2][1]*b.elems[0][2]
        + a.elems[3][1]*b.elems[0][3];

    result.elems[0][2]
        = a.elems[0][2]*b.elems[0][0]
        + a.elems[1][2]*b.elems[0][1]
        + a.elems[2][2]*b.elems[0][2]
        + a.elems[3][2]*b.elems[0][3];

    result.elems[0][3]
        = a.elems[0][3]*b.elems[0][0]
        + a.elems[1][3]*b.elems[0][1]
        + a.elems[2][3]*b.elems[0][2]
        + a.elems[3][3]*b.elems[0][3];

    // Column 1
    result.elems[1][0] 
        = a.elems[0][0]*b.elems[1][0] 
        + a.elems[1][0]*b.elems[1][1] 
        + a.elems[2][0]*b.elems[1][2] 
        + a.elems[3][0]*b.elems[1][3];

    result.elems[1][1] 
        = a.elems[0][1]*b.elems[1][0]
        + a.elems[1][1]*b.elems[1][1]
        + a.elems[2][1]*b.elems[1][2]
        + a.elems[3][1]*b.elems[1][3];

    result.elems[1][2]
        = a.elems[0][2]*b.elems[1][0]
        + a.elems[1][2]*b.elems[1][1]
        + a.elems[2][2]*b.elems[1][2]
        + a.elems[3][2]*b.elems[1][3];

    result.elems[1][3]
        = a.elems[0][3]*b.elems[1][0]
        + a.elems[1][3]*b.elems[1][1]
        + a.elems[2][3]*b.elems[1][2]
        + a.elems[3][3]*b.elems[1][3];

    // Column 2
    result.elems[2][0] 
        = a.elems[0][0]*b.elems[2][0] 
        + a.elems[1][0]*b.elems[2][1] 
        + a.elems[2][0]*b.elems[2][2] 
        + a.elems[3][0]*b.elems[2][3];

    result.elems[2][1] 
        = a.elems[0][1]*b.elems[2][0]
        + a.elems[1][1]*b.elems[2][1]
        + a.elems[2][1]*b.elems[2][2]
        + a.elems[3][1]*b.elems[2][3];

    result.elems[2][2]
        = a.elems[0][2]*b.elems[2][0]
        + a.elems[1][2]*b.elems[2][1]
        + a.elems[2][2]*b.elems[2][2]
        + a.elems[3][2]*b.elems[2][3];

    result.elems[2][3]
        = a.elems[0][3]*b.elems[2][0]
        + a.elems[1][3]*b.elems[2][1]
        + a.elems[2][3]*b.elems[2][2]
        + a.elems[3][3]*b.elems[2][3];

    // Column 3
    result.elems[3][0] 
        = a.elems[0][0]*b.elems[3][0] 
        + a.elems[1][0]*b.elems[3][1] 
        + a.elems[2][0]*b.elems[3][2] 
        + a.elems[3][0]*b.elems[3][3];

    result.elems[3][1] 
        = a.elems[0][1]*b.elems[3][0]
        + a.elems[1][1]*b.elems[3][1]
        + a.elems[2][1]*b.elems[3][2]
        + a.elems[3][1]*b.elems[3][3];

    result.elems[3][2]
        = a.elems[0][2]*b.elems[3][0]
        + a.elems[1][2]*b.elems[3][1]
        + a.elems[2][2]*b.elems[3][2]
        + a.elems[3][2]*b.elems[3][3];

    result.elems[3][3]
        = a.elems[0][3]*b.elems[3][0]
        + a.elems[1][3]*b.elems[3][1]
        + a.elems[2][3]*b.elems[3][2]
        + a.elems[3][3]*b.elems[3][3];

    return result;
}

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

struct mat4 perspective(f64 zfar, f64 znear, f64 aratio, i32 fov){
    assert(aratio != 0);
    assert(znear != zfar);

    struct mat4 result = identityMatrix();

    f64 rad = fov*M_PI/180.0;
    f64 tanHalfFov = tan(rad/2);

    result.elems[0][0] = 1/(aratio*tanHalfFov);
    result.elems[1][1] = 1/tanHalfFov;
    result.elems[2][2] = -((zfar+znear)/(zfar-znear));
    result.elems[2][3] = -1;
    result.elems[3][2] = -((2*zfar*znear)/(zfar-znear));

    return result;
}

/* ******************************************************************************** */

struct mat4 lookat(struct vec4 eye, struct vec4 center, struct vec4 up){
    struct vec4 f = normalize(subVec(center, eye));
    struct vec4 u = normalize(up);
    struct vec4 s = normalize(crossProduct(f, u));

    struct mat4 result = identityMatrix();

    result.elems[0][0] = s.x;
    result.elems[1][0] = s.y;
    result.elems[2][0] = s.z;
    result.elems[0][1] = u.x;
    result.elems[1][1] = u.y;
    result.elems[2][1] = u.z;
    result.elems[0][2] = -f.x;
    result.elems[1][2] = -f.y;
    result.elems[2][2] = -f.z;
    result.elems[3][0] = -dotProduct(s, eye);
    result.elems[3][1] = -dotProduct(u, eye);
    result.elems[3][2] = dotProduct(f, eye);

    return result;
}

/* ******************************************************************************** */