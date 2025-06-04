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
    assert(_x >= -1.0 && _x <= 1.0);
    assert(_y >= -1.0 && _y <= 1.0);
    assert(_z >= -1.0 && _z <= 1.0);
    
    struct vec4 vec;

    vec.x = _x;
    vec.y = _y;
    vec.z = _z;
    vec.w = 1.0;

    return vec;
}

/* ******************************************************************************** */

struct vec4 createVec4_4d(double _x, double _y, double _z, double _w){
    assert(_x >= -1.0 && _x <= 1.0);
    assert(_y >= -1.0 && _y <= 1.0);
    assert(_z >= -1.0 && _z <= 1.0);
    assert(_w >= -1.0 && _w <= 1.0);
    
    struct vec4 vec;

    vec.x = _x;
    vec.y = _y;
    vec.z = _z;
    vec.w = _w;

    return vec;
}

/* ******************************************************************************** */