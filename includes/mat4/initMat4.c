/* ******************************************************************************** */

#include "mat4.h"

/* ******************************************************************************** */

struct mat4 zeroMat4(){
    struct mat4 result;

    result.field[0][0] = 0;
    result.field[0][1] = 0;
    result.field[0][2] = 0;
    result.field[0][3] = 0;

    result.field[1][0] = 0;
    result.field[1][1] = 0;
    result.field[1][2] = 0;
    result.field[1][3] = 0;

    result.field[2][0] = 0;
    result.field[2][1] = 0;
    result.field[2][2] = 0;
    result.field[2][3] = 0;

    result.field[3][0] = 0;
    result.field[3][1] = 0;
    result.field[3][2] = 0;
    result.field[3][3] = 0;

    return result;
}

/* ******************************************************************************** */

struct mat4 oneMat4(){
    struct mat4 result;

    result.field[0][0] = 1;
    result.field[0][1] = 1;
    result.field[0][2] = 1;
    result.field[0][3] = 1;

    result.field[1][0] = 1;
    result.field[1][1] = 1;
    result.field[1][2] = 1;
    result.field[1][3] = 1;

    result.field[2][0] = 1;
    result.field[2][1] = 1;
    result.field[2][2] = 1;
    result.field[2][3] = 1;

    result.field[3][0] = 1;
    result.field[3][1] = 1;
    result.field[3][2] = 1;
    result.field[3][3] = 1;

    return result;
}

/* ******************************************************************************** */

struct mat4 identityMat4(){
    struct mat4 result;

    result.field[0][0] = 1;
    result.field[0][1] = 0;
    result.field[0][2] = 0;
    result.field[0][3] = 0;

    result.field[1][0] = 0;
    result.field[1][1] = 1;
    result.field[1][2] = 0;
    result.field[1][3] = 0;

    result.field[2][0] = 0;
    result.field[2][1] = 0;
    result.field[2][2] = 1;
    result.field[2][3] = 0;

    result.field[3][0] = 0;
    result.field[3][1] = 0;
    result.field[3][2] = 0;
    result.field[3][3] = 1;

    return result;
}

/* ******************************************************************************** */