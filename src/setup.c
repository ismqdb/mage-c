/* ******************************************************************************** */

#include "../includes/glfw setup/glfwSetup.h"
#include "../includes/openglSetup.h"

#include "./globals.h"

/* ******************************************************************************** */

none openglSetup(){
    vertexArray = createVertexArray(GL_TRIANGLES);

    cube = createCube();

    appendVertices(&vertexArray, &cube.vertices);
    appendColors(&vertexArray, &cube.colors);
    appendIndices(&vertexArray, &cube.indices);

    projectionMatrix = perspective(100.0f, 1.0f, 800.0/600, 45);

    viewMatrix = lookat(
        createVec4(0.0f, 0.0f, 1.0f, 1.0f),
        createVec4(0.0f, 0.0f, 0.0f, 1.0f),
        createVec4(0.0f, 1.0f, 0.0f, 1.0f)
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
                cube.modelMatrix = 
                    translateMat4(cube.modelMatrix, createVec4(-deltaX, 0.0f, 0.0f, 1.0f));
                break;

            case GLFW_KEY_RIGHT:
                cube.modelMatrix = 
                    translateMat4(cube.modelMatrix, createVec4(+deltaX, 0.0f, 0.0f, 1.0f));
                break;

            case GLFW_KEY_UP:
                cube.modelMatrix = 
                    translateMat4(cube.modelMatrix, createVec4(0.0f, deltaY, 0.0f, 1.0f));
                break;

            case GLFW_KEY_DOWN:
                cube.modelMatrix = 
                    translateMat4(cube.modelMatrix, createVec4(0.0f, -deltaY, 0.0f, 1.0f));
                break;

            // Rotations
            case GLFW_KEY_A:
                cube.modelMatrix = xrotateMat4(cube.modelMatrix, 10);
                break;
            
            case GLFW_KEY_S:
                cube.modelMatrix = xrotateMat4(cube.modelMatrix, -10);
                break;

            case GLFW_KEY_D:
                cube.modelMatrix = yrotateMat4(cube.modelMatrix, 10);
                break;
            
            case GLFW_KEY_F:
                cube.modelMatrix = yrotateMat4(cube.modelMatrix, -10);
                break;

            case GLFW_KEY_G:
                cube.modelMatrix = zrotateMat4(cube.modelMatrix, 10);
                break;
            
            case GLFW_KEY_H:
                cube.modelMatrix = zrotateMat4(cube.modelMatrix, -10);
                break;

            // Scaling
            case GLFW_KEY_T:
                cube.modelMatrix = scaleMat4(cube.modelMatrix, 0.99f);
                break;

            case GLFW_KEY_Y:
                cube.modelMatrix = scaleMat4(cube.modelMatrix, 1.01f);
                break;

            // Reflect
            case GLFW_KEY_Q:
                cube.modelMatrix = xreflectMat4(cube.modelMatrix);
                break;

            case GLFW_KEY_W:
                cube.modelMatrix = yreflectMat4(cube.modelMatrix);
                break;
        }
    }

    prepareVertexArray(&vertexArray);
}

/* ******************************************************************************** */

none render(f64 currentTime){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat green[] = {0.0f, 0.25f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, green);

    glUniformMatrix4fv(viewMatrixLocation,          1, GL_FALSE, &viewMatrix.field[0][0]);
    glUniformMatrix4fv(projectionMatrixLocation,    1, GL_FALSE, &projectionMatrix.field[0][0]);
    glUniformMatrix4fv(modelMatrixLocation,         1, GL_FALSE, &cube.modelMatrix.field[0][0]);

    renderVertexArray(&vertexArray);
}

/* ******************************************************************************** */

i32 gameLoop(){
    i32 running = 1;

    struct shader shaders[] = {
        {GL_VERTEX_SHADER, "../shaders/vs.vert"},
        {GL_FRAGMENT_SHADER, "../shaders/fs.frag"},
        {GL_NONE, NULL}
    };

    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLuint program = loadShader(shaders);
    glUseProgram(program);

    projectionMatrixLocation = glGetUniformLocation(program, "projection");
    viewMatrixLocation = glGetUniformLocation(program, "view");
    modelMatrixLocation = glGetUniformLocation(program, "model");

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