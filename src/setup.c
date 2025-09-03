/* ******************************************************************************** */

#include "../includes/glfw setup/glfwSetup.h"
#include "../includes/openglSetup.h"

#include "./globals.h"
#include "../includes/rand/rand.h"

/* ******************************************************************************** */

none objectsSetup(){
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

    projectionMatrixLocation = 
        glGetUniformLocation(program, "projection");

    viewMatrixLocation = 
        glGetUniformLocation(program, "view");

    projectionMatrix = perspective(100.0f, 1.0f, 800.0/600, 45);

    viewMatrix = lookat(
        createVec4(0.0f, 0.0f, 1.0f, 1.0f),
        createVec4(0.0f, 0.0f, 0.0f, 1.0f),
        createVec4(0.0f, 1.0f, 0.0f, 1.0f)
    );

    glUniformMatrix4fv(
        viewMatrixLocation,          
        1, 
        GL_FALSE, 
        &viewMatrix.field[0][0]
    );
    
    glUniformMatrix4fv(
        projectionMatrixLocation,    
        1, 
        GL_FALSE, 
        &projectionMatrix.field[0][0]
    );
}

/* ******************************************************************************** */

none openglTeardown(){

}

/* ******************************************************************************** */

none update(){
    f32 deltaX = 1.0/64;
    f32 deltaY = 1.0/64;
    f32 deltaZ = 1.0/64;

    for(i32 i = 0; i < GLFW_KEY_LAST; i++){
        if(!pressed[i])
            continue;

        switch(i){
            // Translations
            case GLFW_KEY_LEFT:
                translateCube(&cube1, createVec4(-deltaX, 0.0f, 0.0f, 1.0f));
                translateCube(&cube2, createVec4(-deltaX, 0.0f, 0.0f, 1.0f));
                break;

            case GLFW_KEY_RIGHT:
                translateCube(&cube1, createVec4(+deltaX, 0.0f, 0.0f, 1.0f));
                translateCube(&cube2, createVec4(+deltaX, 0.0f, 0.0f, 1.0f));
                break;

            case GLFW_KEY_UP:
                translateCube(&cube1, createVec4(0.0f, deltaY, 0.0f, 1.0f));
                translateCube(&cube2, createVec4(0.0f, deltaY, 0.0f, 1.0f));
                break;

            case GLFW_KEY_DOWN:
                translateCube(&cube1, createVec4(0.0f, -deltaY, 0.0f, 1.0f));
                translateCube(&cube2, createVec4(0.0f, -deltaY, 0.0f, 1.0f));
                break;

            // Rotations
            case GLFW_KEY_A:
                xrotateCube(&cube1, 10);
                xrotateCube(&cube2, 10);
                break;
            
            case GLFW_KEY_S:
                xrotateCube(&cube1, -10);
                xrotateCube(&cube2, -10);
                break;

            case GLFW_KEY_D:
                yrotateCube(&cube1, 10);
                yrotateCube(&cube2, 10);
                break;
            
            case GLFW_KEY_F:
                yrotateCube(&cube1, -10);
                yrotateCube(&cube2, -10);
                break;

            case GLFW_KEY_G:
                zrotateCube(&cube1, 10);
                zrotateCube(&cube2, 10);
                break;
            
            case GLFW_KEY_H:
                zrotateCube(&cube1, -10);
                zrotateCube(&cube2, -10);
                break;

            // Scaling
            case GLFW_KEY_T:
                scaleCube(&cube1, 0.99f);
                scaleCube(&cube2, 0.99f);
                break;

            case GLFW_KEY_Y:
                scaleCube(&cube1, 1.01f);
                scaleCube(&cube2, 1.01f);
                break;

            // Reflect
            case GLFW_KEY_Q:
                xreflectCube(&cube1);
                xreflectCube(&cube2);
                break;

            case GLFW_KEY_W:
                yreflectCube(&cube1);
                yreflectCube(&cube2);
                break;
        }
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
    objectsSetup();

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