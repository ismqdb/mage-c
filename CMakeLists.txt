cmake_minimum_required(VERSION 3.10.0)
project(mage VERSION 0.1.0 LANGUAGES C)

# Paths to your local GLFW build (adjust these!)
set(GLFW_ROOT "C:/glfw-3.4.bin.WIN64")

set(GLFW_INCLUDE_DIR "${GLFW_ROOT}/include")
set(GLFW_LIB_DIR "${GLFW_ROOT}/lib-mingw-w64")

set(SOURCE_FILES 
    ./glad/glad.c
    "includes/glfw setup/glfwSetup.c"
    "includes/shader/loadShader.c"
)

set(LIB_FILES
    "includes/array/array.c"
    "includes/rand/rand.c"

    "includes/vertex array/vertexArray.c"
    "includes/vertex attribute/vertexAttribute.c"

    "includes/vec4/vec4.c"
    "includes/point/point.c"

    "includes/mat4/initMat4.c"
    "includes/mat4/operationsMat4.c"
    "includes/mat4/cameraMat4.c"
    "includes/mat4/transformationsMat4.c"

    "includes/uniform/uniform.c"

    "includes/triangle/triangle.c"
    "includes/circle/circle.c"
    "includes/cube/cube.c"
)

add_executable(mage ${SOURCE_FILES} ${LIB_FILES} src/src.c src/setup.c)

target_include_directories(mage PRIVATE
    ${GLFW_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/includes
)

target_link_directories(mage PRIVATE ${GLFW_LIB_DIR})
target_link_libraries(mage PRIVATE glfw3 opengl32 gdi32)