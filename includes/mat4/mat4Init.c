/* ******************************************************************************** */

#include "mat4.h"

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