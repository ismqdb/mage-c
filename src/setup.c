/* ******************************************************************************** */

#include "../includes/glfw setup/glfwSetup.h"
#include "../includes/openglSetup.h"

#include "./globals.h"
#include "../includes/rand/rand.h"

/* ******************************************************************************** */

none objectSetup(){
    for(i32 i = 0; i < noOfCubes; i++)
        cubes[i] = createCube(program);

    for(i32 i = 0; i < noOfCubes; i++)
        scaleCube(&cubes[i], 0.5);

    translateCube(&cubes[0], createVec4(+0.5f, 0.0f, 0.0f, 0.0f));
    translateCube(&cubes[1], createVec4(-0.5f, 0.0f, 0.0f, 0.0f));
    translateCube(&cubes[2], createVec4(+0.5f, 0.0f, 0.0f, 0.0f));
    translateCube(&cubes[3], createVec4(-0.5f, 0.0f, 0.0f, 0.0f));

    translateCube(&cubes[0], createVec4(+0.0f, +0.5f, 0.0f, 0.0f));
    translateCube(&cubes[1], createVec4(-0.0f, +0.5f, 0.0f, 0.0f));
    translateCube(&cubes[2], createVec4(+0.0f, -0.5f, 0.0f, 0.0f));
    translateCube(&cubes[3], createVec4(-0.0f, -0.5f, 0.0f, 0.0f));
}

/* ******************************************************************************** */

none openglSetup(){
    struct shader shaders[] = {
        {GL_VERTEX_SHADER, "../shaders/vs.vert"},
        {GL_FRAGMENT_SHADER, "../shaders/fs.frag"},
        {GL_NONE, NULL}
    };

    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    program = loadShader(shaders);
    glUseProgram(program);

    projection = createMat4Uniform(
        program,
        "projection",
        perspective(100.0f, 1.0f, 800.0/600, 45)
    );

    view = createMat4Uniform(
        program,
        "view",
        lookat(
            createVec4(0.0f, 0.0f, 1.0f, 1.0f),
            createVec4(0.0f, 0.0f, 0.0f, 1.0f),
            createVec4(0.0f, 1.0f, 0.0f, 1.0f)
        )
    );

    setMat4Uniform(&projection);
    setMat4Uniform(&view);
}

/* ******************************************************************************** */

none openglTeardown(){

}

/* ******************************************************************************** */

none update(){
    for(i32 i = 0; i < GLFW_KEY_LAST; i++){
        if(!pressed[i])
            continue;

        for(i32 i = 0; i < noOfCubes; i++)
            onKeyCube(&cubes[i], i);
    }

    for(i32 i = 0; i < noOfCubes; i++)
        updateCube(cubes+i);
}

/* ******************************************************************************** */

none render(f64 currentTime){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat green[] = {0.0f, 0.25f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, green);
    
    for(i32 i = 0; i < noOfCubes; i++)
        renderCube(&cubes[i]);
}

/* ******************************************************************************** */

i32 gameLoop(){
    i32 running = 1;

    openglSetup();
    objectSetup();

    while (running) {
        update();

        glfwSwapBuffers(window);
        glfwPollEvents();

        render(glfwGetTime());

        running &= (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_RELEASE);
        running &= (glfwWindowShouldClose(window) != GL_TRUE);
   }

   return 1;
}

/* ******************************************************************************** */