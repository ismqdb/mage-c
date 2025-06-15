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

struct mat4 rotationMatrix(struct mat4 inputMat, float x, float y, float z){
    assert(x >= -360.0 && x <= 360.0);
    assert(y >= -360.0 && y <= 360.0);
    assert(z >= -360.0 && z <= 360.0);

    inputMat.a00 = cos(y)*cos(z);
    inputMat.a01 = cos(y)*sin(z);
    inputMat.a02 = -sin(y);

    inputMat.a10 = sin(x)*sin(y)*cos(z) - cos(x)*sin(z);
    inputMat.a11 = sin(x)*sin(y)*sin(z) + cos(x)*cos(z);
    inputMat.a12 = sin(x)*cos(y);

    inputMat.a20 = cos(x)*sin(y)*cos(z) + sin(x)*sin(z);
    inputMat.a21 = cos(x)*sin(y)*sin(z) - sin(x)*cos(z);
    inputMat.a22 = cos(x)*cos(y);

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

struct mat4 perspective(double zfar, double znear, double aratio, int fov){
    assert(aratio != 0);
    assert(znear != zfar);

    #ifndef M_PI
        #define M_PI 3.14159265358979323846
    #endif

    struct mat4 result = identityMatrix();

    double rad = fov*M_PI/180.0;
    double tanHalfFov = tan(rad/2);

    result.a00 = 1/(aratio*tanHalfFov);
    result.a11 = 1/tanHalfFov;
    result.a22 = -((zfar+znear)/(zfar-znear));
    result.a23 = -1;
    result.a32 = -((2*zfar*znear)/(zfar-znear));

    return result;
}

/* ******************************************************************************** */

struct mat4 lookat(struct vec4 eye, struct vec4 center, struct vec4 up){
    struct vec4 f = normalize(subVec(center, eye, 1.0));
    struct vec4 u = normalize(up);
    struct vec4 s = normalize(crossProduct(f, u, 1.0));

    struct mat4 result = oneMatrix();

    result.a00 = s.x;
    result.a10 = s.y;
    result.a20 = s.z;
    result.a01 = u.x;
    result.a11 = u.y;
    result.a21 = u.z;
    result.a02 = -f.x;
    result.a12 = -f.y;
    result.a22 = -f.z;
    result.a30 = -dotProduct(s, eye);
    result.a31 = -dotProduct(u, eye);
    result.a32 = dotProduct(f, eye);

    return result;
}

/* ******************************************************************************** */