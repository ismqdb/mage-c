/* ******************************************************************************** */

#include "vec4.h"

/* ******************************************************************************** */

struct vec4 createVec4(f32 _x, f32 _y, f32 _z, f32 _w){
    struct vec4 vec;

    vec.x = _x;
    vec.y = _y;
    vec.z = _z;
    vec.w = _w;

    return vec;
}

/* ******************************************************************************** */

struct vec4 addVec(struct vec4 a, struct vec4 b){
    assert(a.w == b.w);

    struct vec4 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;

    return result;
}

/* ******************************************************************************** */

struct vec4 subVec(struct vec4 a, struct vec4 b){
    assert(a.w == b.w);

    struct vec4 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;

    return result;
}

/* ******************************************************************************** */

f32 magnitude(struct vec4 vec){
    f32 sum = 0;

    sum += vec.x*vec.x;
    sum += vec.y*vec.y;
    sum += vec.z*vec.z;

    return sum;
}

/* ******************************************************************************** */

struct vec4 normalize(struct vec4 vec){
    struct vec4 result;
    f32 _mag = magnitude(vec);

    result.x = vec.x/_mag;
    result.y = vec.y/_mag;
    result.z = vec.z/_mag;

    result.w = vec.w;

    return result;
}

/* ******************************************************************************** */

struct vec4 scalarMul(struct vec4 vec, i32 mul){
    assert(mul != 0);

    struct vec4 result;

    result.x = vec.x*mul;
    result.y = vec.y*mul;
    result.z = vec.z*mul;

    result.w = vec.w;

    return result;
}

/* ******************************************************************************** */

struct vec4 componentProduct(struct vec4 a, struct vec4 b){
    assert(a.w == b.w);

    struct vec4 result;

    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;
    result.w = a.w;

    return result;
}

/* ******************************************************************************** */

f32 dotProduct(struct vec4 a, struct vec4 b){
    struct vec4 result;

    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;

    return result.x + result.y + result.z;
}

/* ******************************************************************************** */

struct vec4 crossProduct(struct vec4 a, struct vec4 b){
    struct vec4 result;

    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * a.x;

    result.w = 0.0;

    return result;
}

/* ******************************************************************************** */