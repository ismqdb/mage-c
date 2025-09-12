/* ******************************************************************************** */

#include "camera.h"

/* ******************************************************************************** */

struct mat4 perspective(f64 zfar, f64 znear, f64 aratio, i32 fov){
    assert(aratio != 0);
    assert(znear != zfar);

    struct mat4 result = identityMat4();

    f64 rad = fov*M_PI/180.0;
    f64 tanHalfFov = tan(rad/2);

    result.field[0][0] = 1/(aratio*tanHalfFov);
    result.field[1][1] = 1/tanHalfFov;
    result.field[2][2] = -((zfar+znear)/(zfar-znear));
    result.field[2][3] = -1;
    result.field[3][2] = -((2*zfar*znear)/(zfar-znear));

    return result;
}

/* ******************************************************************************** */

struct mat4 lookat(struct vec4 eye, struct vec4 center, struct vec4 up){
    struct vec4 f = normalize(subVec(center, eye));
    struct vec4 u = normalize(up);
    struct vec4 s = normalize(crossProduct(f, u));

    struct mat4 result = identityMat4();

    result.field[0][0] = s.x;
    result.field[1][0] = s.y;
    result.field[2][0] = s.z;
    result.field[0][1] = u.x;
    result.field[1][1] = u.y;
    result.field[2][1] = u.z;
    result.field[0][2] = -f.x;
    result.field[1][2] = -f.y;
    result.field[2][2] = -f.z;
    result.field[3][0] = -dotProduct(s, eye);
    result.field[3][1] = -dotProduct(u, eye);
    result.field[3][2] = dotProduct(f, eye);

    return result;
}

/* ******************************************************************************** */

none onKeyCamera(struct uniform *camera, i32 key){

}

/* ******************************************************************************** */