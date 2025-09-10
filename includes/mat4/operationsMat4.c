/* ******************************************************************************** */

#include "mat4.h"

/* ******************************************************************************** */

struct mat4 addMat4(struct mat4 a, struct mat4 b){
    struct mat4 result = zeroMat4();

    result.field[0][0] = a.field[0][0]+b.field[0][0];
    result.field[0][1] = a.field[0][1]+b.field[0][1];
    result.field[0][2] = a.field[0][2]+b.field[0][2];
    result.field[0][3] = a.field[0][3]+b.field[0][3];

    result.field[1][0] = a.field[1][0]+b.field[1][0];
    result.field[1][1] = a.field[1][1]+b.field[1][1];
    result.field[1][2] = a.field[1][2]+b.field[1][2];
    result.field[1][3] = a.field[1][3]+b.field[1][3];

    result.field[2][0] = a.field[2][0]+b.field[2][0];
    result.field[2][1] = a.field[2][1]+b.field[2][1];
    result.field[2][2] = a.field[2][2]+b.field[2][2];
    result.field[2][3] = a.field[2][3]+b.field[2][3];

    result.field[3][0] = a.field[3][0]+b.field[3][0];
    result.field[3][1] = a.field[3][1]+b.field[3][1];
    result.field[3][2] = a.field[3][2]+b.field[3][2];
    result.field[3][3] = a.field[3][3]+b.field[3][3];

    return result;
}

/* ******************************************************************************** */

struct mat4 mulMat4(struct mat4 a, struct mat4 b){
    struct mat4 result = zeroMat4();

    // Column 0
    result.field[0][0] 
        = a.field[0][0]*b.field[0][0] 
        + a.field[1][0]*b.field[0][1] 
        + a.field[2][0]*b.field[0][2] 
        + a.field[3][0]*b.field[0][3];

    result.field[0][1] 
        = a.field[0][1]*b.field[0][0]
        + a.field[1][1]*b.field[0][1]
        + a.field[2][1]*b.field[0][2]
        + a.field[3][1]*b.field[0][3];

    result.field[0][2]
        = a.field[0][2]*b.field[0][0]
        + a.field[1][2]*b.field[0][1]
        + a.field[2][2]*b.field[0][2]
        + a.field[3][2]*b.field[0][3];

    result.field[0][3]
        = a.field[0][3]*b.field[0][0]
        + a.field[1][3]*b.field[0][1]
        + a.field[2][3]*b.field[0][2]
        + a.field[3][3]*b.field[0][3];

    // Column 1
    result.field[1][0] 
        = a.field[0][0]*b.field[1][0] 
        + a.field[1][0]*b.field[1][1] 
        + a.field[2][0]*b.field[1][2] 
        + a.field[3][0]*b.field[1][3];

    result.field[1][1] 
        = a.field[0][1]*b.field[1][0]
        + a.field[1][1]*b.field[1][1]
        + a.field[2][1]*b.field[1][2]
        + a.field[3][1]*b.field[1][3];

    result.field[1][2]
        = a.field[0][2]*b.field[1][0]
        + a.field[1][2]*b.field[1][1]
        + a.field[2][2]*b.field[1][2]
        + a.field[3][2]*b.field[1][3];

    result.field[1][3]
        = a.field[0][3]*b.field[1][0]
        + a.field[1][3]*b.field[1][1]
        + a.field[2][3]*b.field[1][2]
        + a.field[3][3]*b.field[1][3];

    // Column 2
    result.field[2][0] 
        = a.field[0][0]*b.field[2][0] 
        + a.field[1][0]*b.field[2][1] 
        + a.field[2][0]*b.field[2][2] 
        + a.field[3][0]*b.field[2][3];

    result.field[2][1] 
        = a.field[0][1]*b.field[2][0]
        + a.field[1][1]*b.field[2][1]
        + a.field[2][1]*b.field[2][2]
        + a.field[3][1]*b.field[2][3];

    result.field[2][2]
        = a.field[0][2]*b.field[2][0]
        + a.field[1][2]*b.field[2][1]
        + a.field[2][2]*b.field[2][2]
        + a.field[3][2]*b.field[2][3];

    result.field[2][3]
        = a.field[0][3]*b.field[2][0]
        + a.field[1][3]*b.field[2][1]
        + a.field[2][3]*b.field[2][2]
        + a.field[3][3]*b.field[2][3];

    // Column 3
    result.field[3][0] 
        = a.field[0][0]*b.field[3][0] 
        + a.field[1][0]*b.field[3][1] 
        + a.field[2][0]*b.field[3][2] 
        + a.field[3][0]*b.field[3][3];

    result.field[3][1] 
        = a.field[0][1]*b.field[3][0]
        + a.field[1][1]*b.field[3][1]
        + a.field[2][1]*b.field[3][2]
        + a.field[3][1]*b.field[3][3];

    result.field[3][2]
        = a.field[0][2]*b.field[3][0]
        + a.field[1][2]*b.field[3][1]
        + a.field[2][2]*b.field[3][2]
        + a.field[3][2]*b.field[3][3];

    result.field[3][3]
        = a.field[0][3]*b.field[3][0]
        + a.field[1][3]*b.field[3][1]
        + a.field[2][3]*b.field[3][2]
        + a.field[3][3]*b.field[3][3];

    return result;
}

/* ******************************************************************************** */