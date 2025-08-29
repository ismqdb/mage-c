/* ******************************************************************************** */

#include "cube.h"

/* ******************************************************************************** */

struct cube1 createCube(){
    struct cube1 cube1;

    cube1.vertexArray = createVertexArray(GL_TRIANGLES);
    cube1.modelMatrix = identityMat4();

    insertVec4(&cube1.vertexArray.vertices, createPoint(-0.25f, +0.25f, +0.00f, 1.0f).position);
    insertVec4(&cube1.vertexArray.vertices, createPoint(+0.25f, +0.25f, +0.00f, 1.0f).position);
    insertVec4(&cube1.vertexArray.vertices, createPoint(+0.25f, -0.25f, +0.00f, 1.0f).position);
    insertVec4(&cube1.vertexArray.vertices, createPoint(-0.25f, -0.25f, +0.00f, 1.0f).position);

    insertVec4(&cube1.vertexArray.vertices, createPoint(-0.25f, +0.25f, -0.50f, 1.0f).position);
    insertVec4(&cube1.vertexArray.vertices, createPoint(+0.25f, +0.25f, -0.50f, 1.0f).position);
    insertVec4(&cube1.vertexArray.vertices, createPoint(+0.25f, -0.25f, -0.50f, 1.0f).position);
    insertVec4(&cube1.vertexArray.vertices, createPoint(-0.25f, -0.25f, -0.50f, 1.0f).position);

    insertVec4(&cube1.vertexArray.colors, createVec4(+0.95f, +0.25f, +0.80f, 1.0f));
    insertVec4(&cube1.vertexArray.colors, createVec4(+0.95f, +0.75f, +0.20f, 1.0f));
    insertVec4(&cube1.vertexArray.colors, createVec4(+0.95f, +0.95f, +0.70f, 1.0f));
    insertVec4(&cube1.vertexArray.colors, createVec4(-0.95f, +0.15f, +0.50f, 1.0f));

    insertVec4(&cube1.vertexArray.colors, createVec4(+0.25f, +0.45f, +0.70f, 1.0f));
    insertVec4(&cube1.vertexArray.colors, createVec4(+0.95f, +0.05f, +0.80f, 1.0f));
    insertVec4(&cube1.vertexArray.colors, createVec4(+0.95f, +0.05f, +0.30f, 1.0f));
    insertVec4(&cube1.vertexArray.colors, createVec4(+0.05f, +0.55f, +0.40f, 1.0f));

    // Back
    insertIndice(&cube1.vertexArray.indices, 0);
    insertIndice(&cube1.vertexArray.indices, 1);
    insertIndice(&cube1.vertexArray.indices, 2);

    insertIndice(&cube1.vertexArray.indices, 2);
    insertIndice(&cube1.vertexArray.indices, 3);
    insertIndice(&cube1.vertexArray.indices, 0);

    // Front
    insertIndice(&cube1.vertexArray.indices, 4);
    insertIndice(&cube1.vertexArray.indices, 5);
    insertIndice(&cube1.vertexArray.indices, 6);

    insertIndice(&cube1.vertexArray.indices, 4);
    insertIndice(&cube1.vertexArray.indices, 7);
    insertIndice(&cube1.vertexArray.indices, 6);

    // Right
    insertIndice(&cube1.vertexArray.indices, 1);
    insertIndice(&cube1.vertexArray.indices, 5);
    insertIndice(&cube1.vertexArray.indices, 6);

    insertIndice(&cube1.vertexArray.indices, 6);
    insertIndice(&cube1.vertexArray.indices, 2);
    insertIndice(&cube1.vertexArray.indices, 1);

    // Left
    insertIndice(&cube1.vertexArray.indices, 4);
    insertIndice(&cube1.vertexArray.indices, 7);
    insertIndice(&cube1.vertexArray.indices, 3);

    insertIndice(&cube1.vertexArray.indices, 3);
    insertIndice(&cube1.vertexArray.indices, 0);
    insertIndice(&cube1.vertexArray.indices, 4);

    // Top
    insertIndice(&cube1.vertexArray.indices, 1);
    insertIndice(&cube1.vertexArray.indices, 0);
    insertIndice(&cube1.vertexArray.indices, 4);

    insertIndice(&cube1.vertexArray.indices, 4);
    insertIndice(&cube1.vertexArray.indices, 5);
    insertIndice(&cube1.vertexArray.indices, 1);

    // Bottom
    insertIndice(&cube1.vertexArray.indices, 2);
    insertIndice(&cube1.vertexArray.indices, 3);
    insertIndice(&cube1.vertexArray.indices, 7);
    
    insertIndice(&cube1.vertexArray.indices, 7);
    insertIndice(&cube1.vertexArray.indices, 6);
    insertIndice(&cube1.vertexArray.indices, 2);

    return cube1;
}

/* ******************************************************************************** */