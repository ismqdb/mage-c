/* ******************************************************************************** */

#include "../glad/glad.h"

/* ******************************************************************************** */

#include "../includes/vertex array/vertexArray.h"
#include "../includes/circle/circle.h"
#include "../includes/mat4/mat4.h"
#include "../includes/cube/cube.h"

/* ******************************************************************************** */

int pressed[GLFW_KEY_LAST];

/* ******************************************************************************** */

GLint projectionMatrixLocation;
GLint viewMatrixLocation;
GLint modelMatrixLocation;

struct mat4 projectionMatrix;
struct mat4 viewMatrix;
struct mat4 modelMatrix;

struct cube cube;

struct vertexArray vtxarray;

/* ******************************************************************************** */