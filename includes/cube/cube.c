/* ******************************************************************************** */

#include "cube.h"

/* ******************************************************************************** */

struct cube createCube(){
    struct cube cube;

    cube.vertexArray = createVertexArray(GL_TRIANGLES);
    cube.modelMatrix = identityMat4();

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