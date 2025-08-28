/* ******************************************************************************** */

#include "cube.h"

/* ******************************************************************************** */

struct cube createCube(){
    struct cube cube;

    cube.vertices   = fcreateArray();
    cube.colors     = fcreateArray();
    cube.indices    = icreateArray();

    insertVec4(&cube.vertices, createPoint(-0.25f, +0.25f, +0.00f, 1.0f).position);
    insertVec4(&cube.vertices, createPoint(+0.25f, +0.25f, +0.00f, 1.0f).position);
    insertVec4(&cube.vertices, createPoint(+0.25f, -0.25f, +0.00f, 1.0f).position);
    insertVec4(&cube.vertices, createPoint(-0.25f, -0.25f, +0.00f, 1.0f).position);

    insertVec4(&cube.vertices, createPoint(-0.25f, +0.25f, -0.50f, 1.0f).position);
    insertVec4(&cube.vertices, createPoint(+0.25f, +0.25f, -0.50f, 1.0f).position);
    insertVec4(&cube.vertices, createPoint(+0.25f, -0.25f, -0.50f, 1.0f).position);
    insertVec4(&cube.vertices, createPoint(-0.25f, -0.25f, -0.50f, 1.0f).position);

    insertVec4(&cube.colors, createVec4(+0.95f, +0.25f, +0.80f, 1.0f));
    insertVec4(&cube.colors, createVec4(+0.95f, +0.75f, +0.20f, 1.0f));
    insertVec4(&cube.colors, createVec4(+0.95f, +0.95f, +0.70f, 1.0f));
    insertVec4(&cube.colors, createVec4(-0.95f, +0.15f, +0.50f, 1.0f));

    insertVec4(&cube.colors, createVec4(+0.25f, +0.45f, +0.70f, 1.0f));
    insertVec4(&cube.colors, createVec4(+0.95f, +0.05f, +0.80f, 1.0f));
    insertVec4(&cube.colors, createVec4(+0.95f, +0.05f, +0.30f, 1.0f));
    insertVec4(&cube.colors, createVec4(+0.05f, +0.55f, +0.40f, 1.0f));

    // Back
    insertIndice(&cube.indices, 0);
    insertIndice(&cube.indices, 1);
    insertIndice(&cube.indices, 2);

    insertIndice(&cube.indices, 2);
    insertIndice(&cube.indices, 3);
    insertIndice(&cube.indices, 0);

    // Front
    insertIndice(&cube.indices, 4);
    insertIndice(&cube.indices, 5);
    insertIndice(&cube.indices, 6);

    insertIndice(&cube.indices, 4);
    insertIndice(&cube.indices, 7);
    insertIndice(&cube.indices, 6);

    // Right
    insertIndice(&cube.indices, 1);
    insertIndice(&cube.indices, 5);
    insertIndice(&cube.indices, 6);

    insertIndice(&cube.indices, 6);
    insertIndice(&cube.indices, 2);
    insertIndice(&cube.indices, 1);

    // Left
    insertIndice(&cube.indices, 4);
    insertIndice(&cube.indices, 7);
    insertIndice(&cube.indices, 3);

    insertIndice(&cube.indices, 3);
    insertIndice(&cube.indices, 0);
    insertIndice(&cube.indices, 4);

    // Top
    insertIndice(&cube.indices, 1);
    insertIndice(&cube.indices, 0);
    insertIndice(&cube.indices, 4);

    insertIndice(&cube.indices, 4);
    insertIndice(&cube.indices, 5);
    insertIndice(&cube.indices, 1);

    // Bottom
    insertIndice(&cube.indices, 2);
    insertIndice(&cube.indices, 3);
    insertIndice(&cube.indices, 7);
    
    insertIndice(&cube.indices, 7);
    insertIndice(&cube.indices, 6);
    insertIndice(&cube.indices, 2);

    return cube;
}

/* ******************************************************************************** */