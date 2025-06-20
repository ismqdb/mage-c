/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../types.h"
#include "../vec4/vec4.h"

/* ******************************************************************************** */

#include <assert.h>
#include <math.h>

/* ******************************************************************************** */

struct mat4 zeroMatrix();
struct mat4 oneMatrix();
struct mat4 identityMatrix();

/* ******************************************************************************** */

struct mat4 translationMatrix(struct mat4, struct vec4);
struct mat4 scalingMatrix(struct mat4, f32, f32);
struct mat4 rotationMatrix(struct mat4, f32, f32, f32);
struct mat4 reflectMatrix(struct mat4, int, int);

/* ******************************************************************************** */

struct mat4 perspective(f64, f64, f64, int);
struct mat4 lookat(struct vec4, struct vec4, struct vec4);

/* ******************************************************************************** */

struct mat4 {
    f32 a00, a10, a20, a30;
    f32 a01, a11, a21, a31;
    f32 a02, a12, a22, a32;
    f32 a03, a13, a23, a33;
};

/* ******************************************************************************** */