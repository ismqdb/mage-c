/* ******************************************************************************** */

#include "cube.h"

/* ******************************************************************************** */

struct cube createCube(i32 currentProgram){
    assert(currentProgram > 0);

    struct cube cube;
    cube.vertexArray = createVertexArray(GL_TRIANGLES, currentProgram);

    enum {sizePositions = 64};

    f32 positions[sizePositions] = {
        -0.25f, +0.25f, +0.00f, 1.0f,
        +0.25f, +0.25f, +0.00f, 1.0f,
        +0.25f, -0.25f, +0.00f, 1.0f,
        -0.25f, -0.25f, +0.00f, 1.0f,

        -0.25f, +0.25f, -0.50f, 1.0f,
        +0.25f, +0.25f, -0.50f, 1.0f,
        +0.25f, -0.25f, -0.50f, 1.0f,
        -0.25f, -0.25f, -0.50f, 1.0f
    };

    cube.vertexArray.position.value.array = arrayFromRaw_f32(
        ARRAY_TYPE_FLOAT, 
        positions, sizePositions
    );

        insertColorCube(&cube, createVec4(+0.95f, +0.25f, +0.80f, 1.0f));
        insertColorCube(&cube, createVec4(+0.95f, +0.75f, +0.20f, 1.0f));
        insertColorCube(&cube, createVec4(+0.95f, +0.95f, +0.70f, 1.0f));
        insertColorCube(&cube, createVec4(-0.95f, +0.15f, +0.50f, 1.0f));

        insertColorCube(&cube, createVec4(+0.25f, +0.45f, +0.70f, 1.0f));
        insertColorCube(&cube, createVec4(+0.95f, +0.05f, +0.80f, 1.0f));
        insertColorCube(&cube, createVec4(+0.95f, +0.05f, +0.30f, 1.0f));
        insertColorCube(&cube, createVec4(+0.05f, +0.55f, +0.40f, 1.0f));

    enum {sizeIndices = 36};

    i32 indices[sizeIndices] = {
        // Back
        0, 1, 2,
        2, 3, 0,

        // Front
        4, 5, 6,
        4, 7, 6,

        // Right
        1, 5, 6,
        6, 2, 1,

        // Left
        4, 7, 3,
        3, 0, 4,

        // Top
        1, 0, 4,
        4, 5, 1,

        // Bottom
        2, 3, 7,
        7, 6, 2
    };

    cube.vertexArray.indices = arrayFromRaw_i32(ARRAY_TYPE_FLOAT, indices, sizeIndices);

    updateCube(&cube);

    return cube;
}

/* ******************************************************************************** */

none insertPointCube(struct cube *cube, struct point point){
    arrayInsert_vec4(&cube->vertexArray.position.value.array, point.position);
}

/* ******************************************************************************** */

none insertColorCube(struct cube *cube, struct vec4 color){
    arrayInsert_vec4(&cube->vertexArray.color.value.array, color);
}

/* ******************************************************************************** */

none insertIndiceCube(struct cube *cube, i32 ind){
    arrayInsert_i32(&cube->vertexArray.indices, ind);
}

/* ******************************************************************************** */

none xrotateCube(struct cube *cube, f32 value){
    cube->matModel = xrotateMat4(cube->matModel, value);
}

/* ******************************************************************************** */

none yrotateCube(struct cube *cube, f32 value){
    cube->matModel = yrotateMat4(cube->matModel, value);
}

/* ******************************************************************************** */

none zrotateCube(struct cube *cube, f32 value){
    cube->matModel = zrotateMat4(cube->matModel, value);
}

/* ******************************************************************************** */

none translateCube(struct cube* cube, struct vec4 trans){
    cube->matModel = translateMat4(cube->matModel, trans);
}

/* ******************************************************************************** */

none scaleCube(struct cube* cube, f32 factor){
    cube->matModel = scaleMat4(cube->matModel, factor);
}

/* ******************************************************************************** */

none xreflectCube(struct cube *cube){
    cube->matModel = xreflectMat4(cube->matModel);
}

/* ******************************************************************************** */

none yreflectCube(struct cube *cube){
    cube->matModel = yreflectMat4(cube->matModel);
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
    renderVertexArray(&cube->vertexArray);
}

/* ******************************************************************************** */

none updateCube(struct cube *cube){
    updateVertexArray(&cube->vertexArray);
}

/* ******************************************************************************** */