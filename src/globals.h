/* ******************************************************************************** */

#include "../includes/glfw setup/glfwSetup.h"
#include "../includes/openglSetup.h"

/* ******************************************************************************** */

#include "../glad/glad.h"

/* ******************************************************************************** */

#include "../includes/vertex array/vertexArray.h"
#include "../includes/circle/circle.h"
#include "../includes/mat4/mat4.h"
#include "../includes/cube/cube.h"

/* ******************************************************************************** */

GLint projectionMatrixLocation;
GLint viewMatrixLocation;
GLint modelMatrixLocation;

struct mat4 projectionMatrix;
struct mat4 viewMatrix;
struct mat4 modelMatrix;

struct cube1 cube1;
struct cube1 cube2;

struct vertexArray vertexArray;

/* ******************************************************************************** */