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

void translate(struct mat4 *inputMat, f32 tx, f32 ty, f32 tz){
    inputMat->elems[3][0] += tx;
    inputMat->elems[3][1] += ty;
    inputMat->elems[3][2] += tz;
    inputMat->elems[3][3] = 1.0;
}

/* ******************************************************************************** */

void scale(struct mat4 *inputMat, f32 factor){
    assert(factor > 0.0 && factor <= 2.0);

    inputMat->elems[0][0] *= factor;
    inputMat->elems[1][1] *= factor;
    inputMat->elems[2][2] *= factor;
}

/* ******************************************************************************** */

void rotate(struct mat4 *inputMat, f32 x, f32 y, f32 z){
    assert(x >= -360.0 && x <= 360.0);
    assert(y >= -360.0 && y <= 360.0);
    assert(z >= -360.0 && z <= 360.0);

    x = x*M_PI/180;
    y = y*M_PI/180;
    z = z*M_PI/180;

    inputMat->elems[0][0] = cos(y)*cos(z);
    inputMat->elems[0][1] = cos(y)*sin(z);
    inputMat->elems[0][2] = -sin(y);

    inputMat->elems[1][0] = sin(x)*sin(y)*cos(z) - cos(x)*sin(z);
    inputMat->elems[1][1] = sin(x)*sin(y)*sin(z) + cos(x)*cos(z);
    inputMat->elems[1][2] = sin(x)*cos(y);

    inputMat->elems[2][0] = cos(x)*sin(y)*cos(z) + sin(x)*sin(z);
    inputMat->elems[2][1] = cos(x)*sin(y)*sin(z) - sin(x)*cos(z);
    inputMat->elems[2][2] = cos(x)*cos(y);
}

/* ******************************************************************************** */

void reflect(struct mat4 *inputMat, i32 xref, i32 yref){
    assert(xref == 0 || xref == 1);
    assert(yref == 0 || yref == 1);

    if(xref)
        inputMat->elems[1][1] = -1;

    if(yref)
        inputMat->elems[0][0] = -1;
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