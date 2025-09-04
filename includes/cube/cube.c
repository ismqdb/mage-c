/* ******************************************************************************** */

#include "cube.h"

/* ******************************************************************************** */

struct cube createCube(i32 currentProgram){
    assert(currentProgram > 0);

    struct cube cube;

    cube.vertexArray = createVertexArray(GL_TRIANGLES, currentProgram);
    cube.program = currentProgram;

    u8 *name = "model";
    i32 pos = glGetUniformLocation(currentProgram, name);

    cube.modelMatrix = createMat4Uniform(
        pos,
        name,
        identityMat4()
    );

    insertPointCube(&cube, createPoint(-0.25f, +0.25f, +0.00f, 1.0f));
    insertPointCube(&cube, createPoint(+0.25f, +0.25f, +0.00f, 1.0f));
    insertPointCube(&cube, createPoint(+0.25f, -0.25f, +0.00f, 1.0f));
    insertPointCube(&cube, createPoint(-0.25f, -0.25f, +0.00f, 1.0f));

    insertPointCube(&cube, createPoint(-0.25f, +0.25f, -0.50f, 1.0f));
    insertPointCube(&cube, createPoint(+0.25f, +0.25f, -0.50f, 1.0f));
    insertPointCube(&cube, createPoint(+0.25f, -0.25f, -0.50f, 1.0f));
    insertPointCube(&cube, createPoint(-0.25f, -0.25f, -0.50f, 1.0f));

    insertColorCube(&cube, createVec4(+0.95f, +0.25f, +0.80f, 1.0f));
    insertColorCube(&cube, createVec4(+0.95f, +0.75f, +0.20f, 1.0f));
    insertColorCube(&cube, createVec4(+0.95f, +0.95f, +0.70f, 1.0f));
    insertColorCube(&cube, createVec4(-0.95f, +0.15f, +0.50f, 1.0f));

    insertColorCube(&cube, createVec4(+0.25f, +0.45f, +0.70f, 1.0f));
    insertColorCube(&cube, createVec4(+0.95f, +0.05f, +0.80f, 1.0f));
    insertColorCube(&cube, createVec4(+0.95f, +0.05f, +0.30f, 1.0f));
    insertColorCube(&cube, createVec4(+0.05f, +0.55f, +0.40f, 1.0f));

    // Back
    insertIndiceCube(&cube, 0);
    insertIndiceCube(&cube, 1);
    insertIndiceCube(&cube, 2);

    insertIndiceCube(&cube, 2);
    insertIndiceCube(&cube, 3);
    insertIndiceCube(&cube, 0);

    // Front
    insertIndiceCube(&cube, 4);
    insertIndiceCube(&cube, 5);
    insertIndiceCube(&cube, 6);

    insertIndiceCube(&cube, 4);
    insertIndiceCube(&cube, 7);
    insertIndiceCube(&cube, 6);

    // Right
    insertIndiceCube(&cube, 1);
    insertIndiceCube(&cube, 5);
    insertIndiceCube(&cube, 6);

    insertIndiceCube(&cube, 6);
    insertIndiceCube(&cube, 2);
    insertIndiceCube(&cube, 1);

    // Left
    insertIndiceCube(&cube, 4);
    insertIndiceCube(&cube, 7);
    insertIndiceCube(&cube, 3);

    insertIndiceCube(&cube, 3);
    insertIndiceCube(&cube, 0);
    insertIndiceCube(&cube, 4);

    // Top
    insertIndiceCube(&cube, 1);
    insertIndiceCube(&cube, 0);
    insertIndiceCube(&cube, 4);

    insertIndiceCube(&cube, 4);
    insertIndiceCube(&cube, 5);
    insertIndiceCube(&cube, 1);

    // Bottom
    insertIndiceCube(&cube, 2);
    insertIndiceCube(&cube, 3);
    insertIndiceCube(&cube, 7);
    
    insertIndiceCube(&cube, 7);
    insertIndiceCube(&cube, 6);
    insertIndiceCube(&cube, 2);

    return cube;
}

/* ******************************************************************************** */

none insertPointCube(struct cube *cube, struct point point){
    insertVec4(&cube->vertexArray.vertices.value, point.position);
}

/* ******************************************************************************** */

none insertColorCube(struct cube *cube, struct vec4 color){
    insertVec4(&cube->vertexArray.colors.value, color);
}

/* ******************************************************************************** */

none insertIndiceCube(struct cube *cube, i32 ind){
    insertIndice(&cube->vertexArray.indices, ind);
}

/* ******************************************************************************** */

none xrotateCube(struct cube *cube, f32 value){
    cube->modelMatrix.value.m = 
        xrotateMat4(cube->modelMatrix.value.m, value);
}

/* ******************************************************************************** */

none yrotateCube(struct cube *cube, f32 value){
    cube->modelMatrix.value.m = 
        yrotateMat4(cube->modelMatrix.value.m, value);
}

/* ******************************************************************************** */

none zrotateCube(struct cube *cube, f32 value){
    cube->modelMatrix.value.m = 
        zrotateMat4(cube->modelMatrix.value.m, value);
}

/* ******************************************************************************** */

none translateCube(struct cube* cube, struct vec4 trans){
    cube->modelMatrix.value.m =
        translateMat4(cube->modelMatrix.value.m, trans);
}

/* ******************************************************************************** */

none scaleCube(struct cube* cube, f32 factor){
    cube->modelMatrix.value.m =
        scaleMat4(cube->modelMatrix.value.m, factor);
}

/* ******************************************************************************** */

none xreflectCube(struct cube *cube){
    cube->modelMatrix.value.m = 
        xreflectMat4(cube->modelMatrix.value.m);
}

/* ******************************************************************************** */

none yreflectCube(struct cube *cube){
    cube->modelMatrix.value.m = 
        yreflectMat4(cube->modelMatrix.value.m);
}

/* ******************************************************************************** */

none onKeyCube(struct cube *cube, i32 key){
    f32 deltaX = 1.0/64;
    f32 deltaY = 1.0/64;
    f32 deltaZ = 1.0/64;

    switch(key){
        // Translations
        case GLFW_KEY_LEFT:
            translateCube(cube, createVec4(-deltaX, 0.0f, 0.0f, 1.0f));
            break;

        case GLFW_KEY_RIGHT:
            translateCube(cube, createVec4(+deltaX, 0.0f, 0.0f, 1.0f));
            break;

        case GLFW_KEY_UP:
            translateCube(cube, createVec4(0.0f, deltaY, 0.0f, 1.0f));
            break;

        case GLFW_KEY_DOWN:
            translateCube(cube, createVec4(0.0f, -deltaY, 0.0f, 1.0f));
            break;

        // Rotations
        case GLFW_KEY_A:
            xrotateCube(cube, 10);
            break;
        
        case GLFW_KEY_S:
            xrotateCube(cube, -10);
            break;

        case GLFW_KEY_D:
            yrotateCube(cube, 10);
            break;
        
        case GLFW_KEY_F:
            yrotateCube(cube, -10);
            break;

        case GLFW_KEY_G:
            zrotateCube(cube, 10);
            break;
        
        case GLFW_KEY_H:
            zrotateCube(cube, -10);
            break;

        // Scaling
        case GLFW_KEY_T:
            scaleCube(cube, 0.99f);
            break;

        case GLFW_KEY_Y:
            scaleCube(cube, 1.01f);
            break;

        // Reflect
        case GLFW_KEY_Q:
            xreflectCube(cube);
            break;

        case GLFW_KEY_W:
            yreflectCube(cube);
            break;
    }
}

/* ******************************************************************************** */

none renderCube(struct cube *cube){
    glUniformMatrix4fv(
        cube->modelMatrix.position, 
        1, 
        GL_FALSE, 
        &cube->modelMatrix.value.m.field[0][0]
    );

    renderVertexArray(&cube->vertexArray);
}

/* ******************************************************************************** */