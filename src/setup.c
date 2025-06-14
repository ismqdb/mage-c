/* ******************************************************************************** */

#include "../includes/glfw setup/glfwSetup.h"
#include "../includes/openglSetup.h"

#include "./globals.h"

/* ******************************************************************************** */

void openglSetup(){
    vtxarray = createVertexArray(GL_TRIANGLES);

    point1 = createPoint(0.0, 0.50, 0.46, 1.0);
    point2 = createPoint(0.0, -0.50, 0.46, 1.0);
    point3 = createPoint(0.5, 0.0, 0.46, 1.0);

    triangle = createTriangle(point1, point2, point3);

    appendVertices(&vtxarray, &triangle.vertices);
    appendIndices(&vtxarray, &triangle.indices);

    projectionMatrix = identityMatrix();
    viewMatrix = identityMatrix();
    modelMatrix = identityMatrix();

    translationVec = createVec4_3d(-0.5, 0.0, 0.0);

    modelMatrix = translationMatrix(modelMatrix, translationVec);
}

/* ******************************************************************************** */

void openglTeardown(){

}

/* ******************************************************************************** */

void update(){
    for(int i = 0; i < GLFW_KEY_LAST; i++){
        if(!pressed[i])
            continue;

        switch(i){
            case GLFW_KEY_LEFT:
                break;

            case GLFW_KEY_RIGHT:

                break;

            case GLFW_KEY_UP:
                break;

            case GLFW_KEY_DOWN:

                break;

            case GLFW_KEY_A:

                break;
            
            case GLFW_KEY_D:

                break;
        }
    }

    preparevtx(&vtxarray);
}

/* ******************************************************************************** */

void render(double currentTime){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat green[] = {0.0f, 0.25f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, green);

    glUniformMatrix4fv(viewMatrixLocation,          1, GL_FALSE, &viewMatrix.a00);
    glUniformMatrix4fv(projectionMatrixLocation,    1, GL_FALSE, &projectionMatrix.a00);
    glUniformMatrix4fv(modelMatrixLocation,         1, GL_FALSE, &modelMatrix.a00);

    rendervtx(&vtxarray);
}

/* ******************************************************************************** */

int gameLoop(){
    int running = 1;

    struct shader shaders[] = {
        {GL_VERTEX_SHADER, "../shaders/vs.vert"},
        {GL_FRAGMENT_SHADER, "../shaders/fs.frag"},
        {GL_NONE, NULL}
    };

    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glPointSize(10);

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