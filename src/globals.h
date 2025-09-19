/* ******************************************************************************** */

#include "../includes/glfw setup/glfwSetup.h"
#include "../includes/openglSetup.h"

/* ******************************************************************************** */

#include "../glad/glad.h"

/* ******************************************************************************** */

#include "../includes/vertex array/vertexArray.h"
#include "../includes/circle/circle.h"
#include "../includes/mat4/mat4.h"
#include "../includes/camera/camera.h"
#include "../includes/cube/cube.h"
#include "../includes/uniform/uniform.h"

#include "../includes/rand/rand.h"

/* ******************************************************************************** */

enum {noOfCubes = 444};

GLuint program;

struct uniform projection;
struct uniform view;

struct cube cubes[noOfCubes];

/* ******************************************************************************** */