cmake_minimum_required(VERSION 3.10.0)
project(mage VERSION 0.1.0 LANGUAGES C)

set(CMAKE_EXE_LINKER_FLAGS "-lglfw -lm")

set(SOURCE_FILES 
    ./glad/glad.c
    "includes/glfw setup/glfwSetup.c"
    "includes/shader/loadShader.c"
)

set(LIB_FILES
    "includes/array/array.c"
    "includes/vertex array/vertexArray.c"
    "includes/vec4/vec4.c"
    "includes/point/point.c"
    "includes/triangle/triangle.c"
    "includes/circle/circle.c"
)

add_executable(mage ${SOURCE_FILES} ${LIB_FILES} src/src.c src/setup.c)

add_executable(test test.c
    ${SOURCE_FILES}
    ${LIB_FILES}
)