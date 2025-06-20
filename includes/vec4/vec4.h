/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../types.h"

/* ******************************************************************************** */

#include <assert.h>
#include <math.h>

/* ******************************************************************************** */

struct vec4 directionVec(double, double, double);
struct vec4 pointVec(double, double, double);

/* ******************************************************************************** */

struct vec4 addVec(struct vec4, struct vec4);
struct vec4 subVec(struct vec4, struct vec4);

/* ******************************************************************************** */

double magnitude(struct vec4);
struct vec4 normalize(struct vec4);
struct vec4 scalarMul(struct vec4, int);

/* ******************************************************************************** */

struct vec4 componentProduct(struct vec4, struct vec4, double);
double dotProduct(struct vec4, struct vec4);
struct vec4 crossProduct(struct vec4, struct vec4);

/* ******************************************************************************** */

struct vec4 {
    double x;
    double y;
    double z;
    double w;
};

/* ******************************************************************************** */