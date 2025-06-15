/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../vec4/vec4.h"

/* ******************************************************************************** */

#include <assert.h>
#include <math.h>

/* ******************************************************************************** */

struct mat4 zeroMatrix();
struct mat4 identityMatrix();

/* ******************************************************************************** */

struct mat4 translationMatrix(struct mat4, struct vec4);
struct mat4 scalingMatrix(struct mat4, float, float);
struct mat4 rotationMatrix(struct mat4, float, float, float);
struct mat4 reflectMatrix(struct mat4, int, int);

/* ******************************************************************************** */

struct mat4 perspective(double, double, double, int);
struct mat4 lookat(struct vec4, struct vec4, struct vec4);

/* ******************************************************************************** */

struct mat4 {
    float a00, a10, a20, a30;
    float a01, a11, a21, a31;
    float a02, a12, a22, a32;
    float a03, a13, a23, a33;
};

/* ******************************************************************************** */