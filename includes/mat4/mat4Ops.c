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