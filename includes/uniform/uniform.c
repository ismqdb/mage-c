/* ******************************************************************************** */

#include "uniform.h"

/* ******************************************************************************** */

struct uniform createMat4Uniform(i32 program, u8 *name, struct mat4 mat){
    struct uniform uniform;

    uniform.name = name;
    uniform.position = glGetUniformLocation(program, name);
    uniform.value.m = mat;

    return uniform;
}

/* ******************************************************************************** */

struct uniform createVec4Uniform(i32 program, u8 *name, struct vec4 vec){
    struct uniform uniform;

    uniform.name = name;
    uniform.position = glGetUniformLocation(program, name);
    uniform.value.v = vec;

    return uniform;
}

/* ******************************************************************************** */

none setMat4Uniform(struct uniform *uniform){
    glUniformMatrix4fv(
        uniform->position,    
        1, 
        GL_FALSE, 
        &uniform->value.m.field[0][0]
    );
}

/* ******************************************************************************** */