/* ******************************************************************************** */

#include "vec4.h"

/* ******************************************************************************** */

struct vec4 createVec4(){
    struct vec4 vec;

    vec.x = 0.0;
    vec.y = 0.0;
    vec.z = 0.0;
    vec.w = 1.0;

    return vec;
}

/* ******************************************************************************** */

struct vec4 createVec4_3d(double _x, double _y, double _z){
    struct vec4 vec;

    vec.x = _x;
    vec.y = _y;
    vec.z = _z;
    vec.w = 1.0;

    return vec;
}

/* ******************************************************************************** */

struct vec4 createVec4_4d(double _x, double _y, double _z, double _w){
    struct vec4 vec;

    vec.x = _x;
    vec.y = _y;
    vec.z = _z;
    vec.w = _w;

    return vec;
}

/* ******************************************************************************** */