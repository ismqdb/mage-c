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

GLuint program;

GLint projectionMatrixLocation;
GLint viewMatrixLocation;

struct mat4 projectionMatrix;
struct mat4 viewMatrix;

struct cube cube1;
struct cube cube2;

struct vertexArray vertexArray;

/* ******************************************************************************** */