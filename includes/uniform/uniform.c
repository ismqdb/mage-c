/* ******************************************************************************** */

#include "uniform.h"

/* ******************************************************************************** */

struct uniform createMat4Uniform(u8* n, i32 pos, struct mat4 mat){
    struct uniform uniform;

    uniform.type = UNIFORM_TYPE_MAT4;
    uniform.name = n;
    uniform.position = pos;
    uniform.value.m = mat;

    return uniform;
}

/* ******************************************************************************** */

struct uniform createVec4Uniform(u8* n, i32 pos, struct vec4 vec){
    struct uniform uniform;

    uniform.type = UNIFORM_TYPE_VEC4;
    uniform.name = n;
    uniform.position = pos;
    uniform.value.v = vec;

    return uniform;
}

/* ******************************************************************************** */