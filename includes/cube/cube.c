/* ******************************************************************************** */

#include "cube.h"

/* ******************************************************************************** */

struct cube makeCube(){
    struct cube cube;

    cube.vertices = vcreateArray();
    cube.indices = icreateArray();

    insertPoint(&cube.vertices, createPoint(-0.25f, +0.25f, +0.00f, 1.0f));
    insertPoint(&cube.vertices, createPoint(+0.25f, +0.25f, +0.00f, 1.0f));
    insertPoint(&cube.vertices, createPoint(+0.25f, -0.25f, +0.00f, 1.0f));
    insertPoint(&cube.vertices, createPoint(-0.25f, -0.25f, +0.00f, 1.0f));

    insertPoint(&cube.vertices, createPoint(-0.25f, +0.25f, -0.50f, 1.0f));
    insertPoint(&cube.vertices, createPoint(+0.25f, +0.25f, -0.50f, 1.0f));
    insertPoint(&cube.vertices, createPoint(+0.25f, -0.25f, -0.50f, 1.0f));
    insertPoint(&cube.vertices, createPoint(-0.25f, -0.25f, -0.50f, 1.0f));

    // Front
    insertIndice(&cube.indices, 0);
    insertIndice(&cube.indices, 1);
    insertIndice(&cube.indices, 2);
    insertIndice(&cube.indices, 2);
    insertIndice(&cube.indices, 3);
    insertIndice(&cube.indices, 0);

    // Back
    insertIndice(&cube.indices, 4);
    insertIndice(&cube.indices, 5);
    insertIndice(&cube.indices, 6);
    insertIndice(&cube.indices, 5);
    insertIndice(&cube.indices, 6);
    insertIndice(&cube.indices, 7);

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