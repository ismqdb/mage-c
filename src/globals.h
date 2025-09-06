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
#include "../includes/uniform/uniform.h"

/* ******************************************************************************** */

GLuint program;

struct uniform projection;
struct uniform view;

struct cube cube;

struct vertexArray vertexArray;

/* ******************************************************************************** */