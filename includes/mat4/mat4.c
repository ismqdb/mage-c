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