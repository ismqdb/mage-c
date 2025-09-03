/* ******************************************************************************** */

#include "../includes/glfw setup/glfwSetup.h"
#include "../includes/openglSetup.h"

#include "./globals.h"
#include "../includes/rand/rand.h"

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

    cube1 = createCube(program);
    cube2 = createCube(program);

    projectionMatrix = perspective(100.0f, 1.0f, 800.0/600, 45);

    viewMatrix = lookat(
        createVec4(0.0f, 0.0f, 1.0f, 1.0f),
        createVec4(0.0f, 0.0f, 0.0f, 1.0f),
        createVec4(0.0f, 1.0f, 0.0f, 1.0f)
    );

    cube1.modelMatrix.value = 
        translateMat4(cube1.modelMatrix.value, createVec4(-0.35f, 0.0f, 0.0f, 0.0f));

    cube2.modelMatrix.value = 
        translateMat4(cube2.modelMatrix.value, createVec4(+0.35f, 0.0f, 0.0f, 0.0f));

    cube1.modelMatrix.value =
        scaleMat4(cube1.modelMatrix.value, 0.5f);

    cube2.modelMatrix.value = 
        scaleMat4(cube2.modelMatrix.value, 0.5f);
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
                cube1.modelMatrix.value = 
                    translateMat4(cube1.modelMatrix.value, createVec4(-deltaX, 0.0f, 0.0f, 1.0f));

                cube2.modelMatrix.value = 
                    translateMat4(cube2.modelMatrix.value, createVec4(-deltaX, 0.0f, 0.0f, 1.0f));
                break;

            case GLFW_KEY_RIGHT:
                cube1.modelMatrix.value = 
                    translateMat4(cube1.modelMatrix.value, createVec4(+deltaX, 0.0f, 0.0f, 1.0f));

                cube2.modelMatrix.value = 
                    translateMat4(cube2.modelMatrix.value, createVec4(+deltaX, 0.0f, 0.0f, 1.0f));
                break;

            case GLFW_KEY_UP:
                cube1.modelMatrix.value = 
                    translateMat4(cube1.modelMatrix.value, createVec4(0.0f, deltaY, 0.0f, 1.0f));

                cube2.modelMatrix.value = 
                    translateMat4(cube2.modelMatrix.value, createVec4(0.0f, deltaY, 0.0f, 1.0f));
                break;

            case GLFW_KEY_DOWN:
                cube1.modelMatrix.value = 
                    translateMat4(cube1.modelMatrix.value, createVec4(0.0f, -deltaY, 0.0f, 1.0f));

                cube2.modelMatrix.value = 
                    translateMat4(cube2.modelMatrix.value, createVec4(0.0f, -deltaY, 0.0f, 1.0f));
                break;

            // Rotations
            case GLFW_KEY_A:
                cube1.modelMatrix.value = xrotateMat4(cube1.modelMatrix.value, 10);
                cube2.modelMatrix.value = xrotateMat4(cube2.modelMatrix.value, 10);
                break;
            
            case GLFW_KEY_S:
                cube1.modelMatrix.value = xrotateMat4(cube1.modelMatrix.value, -10);
                cube2.modelMatrix.value = xrotateMat4(cube2.modelMatrix.value, -10);
                break;

            case GLFW_KEY_D:
                cube1.modelMatrix.value = yrotateMat4(cube1.modelMatrix.value, 10);
                cube2.modelMatrix.value = yrotateMat4(cube2.modelMatrix.value, 10);
                break;
            
            case GLFW_KEY_F:
                cube1.modelMatrix.value = yrotateMat4(cube1.modelMatrix.value, -10);
                cube2.modelMatrix.value = yrotateMat4(cube2.modelMatrix.value, -10);
                break;

            case GLFW_KEY_G:
                cube1.modelMatrix.value = zrotateMat4(cube1.modelMatrix.value, 10);
                cube2.modelMatrix.value = zrotateMat4(cube2.modelMatrix.value, 10);
                break;
            
            case GLFW_KEY_H:
                cube1.modelMatrix.value = zrotateMat4(cube1.modelMatrix.value, -10);
                cube2.modelMatrix.value = zrotateMat4(cube2.modelMatrix.value, -10);
                break;

            // Scaling
            case GLFW_KEY_T:
                cube1.modelMatrix.value = scaleMat4(cube1.modelMatrix.value, 0.99f);
                cube2.modelMatrix.value = scaleMat4(cube2.modelMatrix.value, 0.99f);
                break;

            case GLFW_KEY_Y:
                cube1.modelMatrix.value = scaleMat4(cube1.modelMatrix.value, 1.01f);
                cube2.modelMatrix.value = scaleMat4(cube2.modelMatrix.value, 1.01f);
                break;

            // Reflect
            case GLFW_KEY_Q:
                cube1.modelMatrix.value = xreflectMat4(cube1.modelMatrix.value);
                cube2.modelMatrix.value = xreflectMat4(cube2.modelMatrix.value);
                break;

            case GLFW_KEY_W:
                cube1.modelMatrix.value = yreflectMat4(cube1.modelMatrix.value);
                cube2.modelMatrix.value = yreflectMat4(cube2.modelMatrix.value);
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
    
    renderCube(&cube1);
    renderCube(&cube2);
}

/* ******************************************************************************** */

i32 gameLoop(){
    i32 running = 1;

    openglSetup();

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