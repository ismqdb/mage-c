/* ******************************************************************************** */

#include "mat4.h"

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