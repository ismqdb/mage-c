/* ******************************************************************************** */

#include "../includes/glfw setup/glfwSetup.h"
#include "../includes/openglSetup.h"

#include "./globals.h"
#include "../includes/rand/rand.h"

/* ******************************************************************************** */

none objectSetup(){
    cube1 = createCube(program);
    cube2 = createCube(program);

    translateCube(&cube1, createVec4(-0.35f, 0.0f, 0.0f, 0.0f));
    translateCube(&cube2, createVec4(+0.35f, 0.0f, 0.0f, 0.0f));

    scaleCube(&cube1, 0.5f);
    scaleCube(&cube2, 0.5f);
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


    viewMatrixLocation = 
        glGetUniformLocation(program, "view");

    projection = createMat4Uniform(
        program,
        "projection",
        perspective(100.0f, 1.0f, 800.0/600, 45)
    );

    viewMatrix = lookat(
        createVec4(0.0f, 0.0f, 1.0f, 1.0f),
        createVec4(0.0f, 0.0f, 0.0f, 1.0f),
        createVec4(0.0f, 1.0f, 0.0f, 1.0f)
    );

    glUniformMatrix4fv(
        projection.position,    
        1, 
        GL_FALSE, 
        &projection.value.m.field[0][0]
    );

    glUniformMatrix4fv(
        viewMatrixLocation,          
        1, 
        GL_FALSE, 
        &viewMatrix.field[0][0]
    );
}

/* ******************************************************************************** */

none openglTeardown(){

}

/* ******************************************************************************** */

none update(){
    for(i32 i = 0; i < GLFW_KEY_LAST; i++){
        if(!pressed[i])
            continue;

        onKeyCube(&cube1, i);
        onKeyCube(&cube2, i);
    }

    prepareVertexArray(&cube1.vertexArray);
    prepareVertexArray(&cube2.vertexArray);
}

/* ******************************************************************************** */

none render(f64 currentTime){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat green[] = {0.0f, 0.25f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, green);
    
    renderCube(&cube1);
    renderCube(&cube2);
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