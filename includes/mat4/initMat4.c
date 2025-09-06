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

struct mat4 randomMat4(f32 lo, f32 hi){
    assert(lo >= -1.0f && lo <= 1.0f);
    assert(hi >= -1.0f && hi <= 1.0f);

    assert(lo < hi);

    struct mat4 result;

    for(i32 i = 0; i < 3; i++)
        for(i32 j = 0; j < 3; j++)
            result.field[i][j] = fgetRand(lo, hi);

    result.field[0][3] = 1;
    result.field[1][3] = 1;
    result.field[2][3] = 1;
    result.field[3][3] = 1;

    return result;
}

/* ******************************************************************************** */