/* ******************************************************************************** */

#include "../includes/glfw setup/glfwSetup.h"
#include "../includes/openglSetup.h"

#include "./globals.h"
#include "../includes/rand/rand.h"

/* ******************************************************************************** */

none objectSetup(){
    cube = createCube(program);

    scaleCube(&cube, 0.5f);
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

        onKeyCube(&cube, i);
    }

    prepareVertexArray(&cube.vertexArray);
}

/* ******************************************************************************** */

none render(f64 currentTime){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat green[] = {0.0f, 0.25f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, green);
    
    renderCube(&cube);
}

/* ******************************************************************************** */

i32 gameLoop(){
    i32 running = 1;

    openglSetup();
    objectSetup();

    while (running) {
        render(glfwGetTime());

        glfwSwapBuffers(window);
        glfwPollEvents();

        update();

        running &= (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_RELEASE);
        running &= (glfwWindowShouldClose(window) != GL_TRUE);
   }

   return 1;
}

/* ******************************************************************************** */