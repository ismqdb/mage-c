/* ******************************************************************************** */

#include "../glad/glad.h"

/* ******************************************************************************** */

#include "../includes/vertex array/vertexArray.h"
#include "../includes/circle/circle.h"

/* ******************************************************************************** */

int pressed[GLFW_KEY_LAST];

/* ******************************************************************************** */

GLint projectionMatrixLocation;
GLint viewMatrixLocation;
GLint modelMatrixLocation;

struct point point1;
struct point point2;
struct point point3;

struct triangle triangle;

struct vertexArray vtxarray;

/* ******************************************************************************** */