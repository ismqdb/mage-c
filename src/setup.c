/* ******************************************************************************** */

#include "../includes/glfw setup/glfwSetup.h"
#include "../includes/openglSetup.h"

#include "./globals.h"

/* ******************************************************************************** */

void openglSetup(){
    vtxarray = createVertexArray(GL_TRIANGLES);

    cube = createCube();

    appendVertices(&vtxarray, &cube.vertices);
    appendIndices(&vtxarray, &cube.indices);

    projectionMatrix = perspective(100.0f, 1.0f, 800.0/600, 45);

    viewMatrix = lookat(
        createVector(0.0f, 0.0f, 1.0f, 1.0f),
        createVector(0.0f, 0.0f, 0.0f, 1.0f),
        createVector(0.0f, 1.0f, 0.0f, 1.0f)
    );

    modelMatrix = identityMatrix();
}

/* ******************************************************************************** */

void openglTeardown(){

}

/* ******************************************************************************** */

void update(){
    f32 deltaX = 1.0/64;
    f32 deltaY = 1.0/64;
    f32 deltaZ = 1.0/64;

    f32 rotDeltaX = 0.25f;
    f32 rotDeltaY = 0.25f;

    for(i32 i = 0; i < GLFW_KEY_LAST; i++){
        if(!pressed[i])
            continue;

        switch(i){
            case GLFW_KEY_LEFT:
                translate(&modelMatrix, -deltaX, 0.0f, 0.0f);
                break;

            case GLFW_KEY_RIGHT:
                translate(&modelMatrix, +deltaX, 0.0f, 0.0f);
                break;

            case GLFW_KEY_UP:
                translate(&modelMatrix, 0.0f, +deltaY, 0.0f);
                break;

            case GLFW_KEY_DOWN:
                translate(&modelMatrix, 0.0f, -deltaY, 0.0f);
                break;

            case GLFW_KEY_A:
                rotate(&modelMatrix, 10.0, 0.0, 0.0);
                break;
            
            case GLFW_KEY_D:
                rotate(&modelMatrix, 10.0, 0.0, 0.0);
                break;

            case GLFW_KEY_Q:
                reflect(&modelMatrix, 1, 0);
                break;

            case GLFW_KEY_W:
                reflect(&modelMatrix, 0, 1);
                break;
        }
    }

    preparevtx(&vtxarray);
}

/* ******************************************************************************** */

void render(f64 currentTime){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat green[] = {0.0f, 0.25f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, green);

    glUniformMatrix4fv(viewMatrixLocation,          1, GL_FALSE, &viewMatrix.elems[0][0]);
    glUniformMatrix4fv(projectionMatrixLocation,    1, GL_FALSE, &projectionMatrix.elems[0][0]);
    glUniformMatrix4fv(modelMatrixLocation,         1, GL_FALSE, &modelMatrix.elems[0][0]);

    rendervtx(&vtxarray);
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