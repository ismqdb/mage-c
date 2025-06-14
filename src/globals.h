/* ******************************************************************************** */

#include "../glad/glad.h"

/* ******************************************************************************** */

#include "../includes/vertex array/vertexArray.h"
#include "../includes/circle/circle.h"
#include "../includes/mat4/mat4.h"

/* ******************************************************************************** */

int pressed[GLFW_KEY_LAST];

/* ******************************************************************************** */

GLint projectionMatrixLocation;
GLint viewMatrixLocation;
GLint modelMatrixLocation;

struct mat4 projectionMatrix;
struct mat4 viewMatrix;
struct mat4 modelMatrix;

struct point point1;
struct point point2;
struct point point3;

struct triangle triangle;

struct vertexArray vtxarray;

/* ******************************************************************************** */