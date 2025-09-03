/* ******************************************************************************** */

#include "cube.h"

/* ******************************************************************************** */

struct cube createCube(i32 currentProgram){
    assert(currentProgram > 0);

    struct cube cube;

    cube.vertexArray = createVertexArray(GL_TRIANGLES);
    cube.program = currentProgram;

    cube.modelMatrix.name = "model";
    cube.modelMatrix.position = 
        glGetUniformLocation(currentProgram, cube.modelMatrix.name);
    cube.modelMatrix.value = identityMat4();

    insertVec4(&cube.vertexArray.vertices, createPoint(-0.25f, +0.25f, +0.00f, 1.0f).position);
    insertVec4(&cube.vertexArray.vertices, createPoint(+0.25f, +0.25f, +0.00f, 1.0f).position);
    insertVec4(&cube.vertexArray.vertices, createPoint(+0.25f, -0.25f, +0.00f, 1.0f).position);
    insertVec4(&cube.vertexArray.vertices, createPoint(-0.25f, -0.25f, +0.00f, 1.0f).position);

    insertVec4(&cube.vertexArray.vertices, createPoint(-0.25f, +0.25f, -0.50f, 1.0f).position);
    insertVec4(&cube.vertexArray.vertices, createPoint(+0.25f, +0.25f, -0.50f, 1.0f).position);
    insertVec4(&cube.vertexArray.vertices, createPoint(+0.25f, -0.25f, -0.50f, 1.0f).position);
    insertVec4(&cube.vertexArray.vertices, createPoint(-0.25f, -0.25f, -0.50f, 1.0f).position);

    insertVec4(&cube.vertexArray.colors, createVec4(+0.95f, +0.25f, +0.80f, 1.0f));
    insertVec4(&cube.vertexArray.colors, createVec4(+0.95f, +0.75f, +0.20f, 1.0f));
    insertVec4(&cube.vertexArray.colors, createVec4(+0.95f, +0.95f, +0.70f, 1.0f));
    insertVec4(&cube.vertexArray.colors, createVec4(-0.95f, +0.15f, +0.50f, 1.0f));

    insertVec4(&cube.vertexArray.colors, createVec4(+0.25f, +0.45f, +0.70f, 1.0f));
    insertVec4(&cube.vertexArray.colors, createVec4(+0.95f, +0.05f, +0.80f, 1.0f));
    insertVec4(&cube.vertexArray.colors, createVec4(+0.95f, +0.05f, +0.30f, 1.0f));
    insertVec4(&cube.vertexArray.colors, createVec4(+0.05f, +0.55f, +0.40f, 1.0f));

    // Back
    insertIndice(&cube.vertexArray.indices, 0);
    insertIndice(&cube.vertexArray.indices, 1);
    insertIndice(&cube.vertexArray.indices, 2);

    insertIndice(&cube.vertexArray.indices, 2);
    insertIndice(&cube.vertexArray.indices, 3);
    insertIndice(&cube.vertexArray.indices, 0);

    // Front
    insertIndice(&cube.vertexArray.indices, 4);
    insertIndice(&cube.vertexArray.indices, 5);
    insertIndice(&cube.vertexArray.indices, 6);

    insertIndice(&cube.vertexArray.indices, 4);
    insertIndice(&cube.vertexArray.indices, 7);
    insertIndice(&cube.vertexArray.indices, 6);

    // Right
    insertIndice(&cube.vertexArray.indices, 1);
    insertIndice(&cube.vertexArray.indices, 5);
    insertIndice(&cube.vertexArray.indices, 6);

    insertIndice(&cube.vertexArray.indices, 6);
    insertIndice(&cube.vertexArray.indices, 2);
    insertIndice(&cube.vertexArray.indices, 1);

    // Left
    insertIndice(&cube.vertexArray.indices, 4);
    insertIndice(&cube.vertexArray.indices, 7);
    insertIndice(&cube.vertexArray.indices, 3);

    insertIndice(&cube.vertexArray.indices, 3);
    insertIndice(&cube.vertexArray.indices, 0);
    insertIndice(&cube.vertexArray.indices, 4);

    // Top
    insertIndice(&cube.vertexArray.indices, 1);
    insertIndice(&cube.vertexArray.indices, 0);
    insertIndice(&cube.vertexArray.indices, 4);

    insertIndice(&cube.vertexArray.indices, 4);
    insertIndice(&cube.vertexArray.indices, 5);
    insertIndice(&cube.vertexArray.indices, 1);

    // Bottom
    insertIndice(&cube.vertexArray.indices, 2);
    insertIndice(&cube.vertexArray.indices, 3);
    insertIndice(&cube.vertexArray.indices, 7);
    
    insertIndice(&cube.vertexArray.indices, 7);
    insertIndice(&cube.vertexArray.indices, 6);
    insertIndice(&cube.vertexArray.indices, 2);

    return cube;
}

/* ******************************************************************************** */

none xrotateCube(struct cube *cube, f32 value){
    cube->modelMatrix.value = 
        xrotateMat4(cube->modelMatrix.value, value);
}

/* ******************************************************************************** */

none yrotateCube(struct cube *cube, f32 value){
    cube->modelMatrix.value = 
        yrotateMat4(cube->modelMatrix.value, value);
}

/* ******************************************************************************** */

none zrotateCube(struct cube *cube, f32 value){
    cube->modelMatrix.value = 
        zrotateMat4(cube->modelMatrix.value, value);
}

/* ******************************************************************************** */

none translateCube(struct cube* cube, struct vec4 trans){
    cube->modelMatrix.value =
        translateMat4(cube->modelMatrix.value, trans);
}

/* ******************************************************************************** */

none scaleCube(struct cube* cube, f32 factor){
    cube->modelMatrix.value =
        scaleMat4(cube->modelMatrix.value, factor);
}

/* ******************************************************************************** */

none xreflectCube(struct cube *cube){
    cube->modelMatrix.value = 
        xreflectMat4(cube->modelMatrix.value);
}

/* ******************************************************************************** */

none yreflectCube(struct cube *cube){
    cube->modelMatrix.value = 
        yreflectMat4(cube->modelMatrix.value);
}

/* ******************************************************************************** */

none renderCube(struct cube *cube){
    glUniformMatrix4fv(
        cube->modelMatrix.position, 
        1, 
        GL_FALSE, 
        &cube->modelMatrix.value.field[0][0]
    );

    renderVertexArray(&cube->vertexArray);
}

/* ******************************************************************************** */