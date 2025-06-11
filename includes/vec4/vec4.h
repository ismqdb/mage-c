/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <assert.h>
#include <math.h>

/* ******************************************************************************** */

struct vec4 createVec4();
struct vec4 createVec4_3d(double, double, double);
struct vec4 createVec4_4d(double, double, double, double);

/* ******************************************************************************** */

struct vec4 addVec(struct vec4, struct vec4, double);
struct vec4 subVec(struct vec4, struct vec4, double);

/* ******************************************************************************** */

double magnitude(struct vec4);
struct vec4 normalize(struct vec4);

/* ******************************************************************************** */

struct vec4 {
    double x;
    double y;
    double z;
    double w;
};

/* ******************************************************************************** */