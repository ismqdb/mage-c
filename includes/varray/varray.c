/* ******************************************************************************** */

#include "./varray.h"

/* ******************************************************************************** */

struct varray vcreateArray(){
    struct varray array;

    array.size = 0;
    array.capacity = 16;
    
    array.elems = heapAllocSized(float, array.capacity);
    array.elems[0] = '\0';

    return array;
}

/* ******************************************************************************** */

void vdestroyArray(struct varray *array){
    array->size = 0;
    free(array->elems);
}

/* ******************************************************************************** */

void vreserve(struct varray *array){
    array->capacity *= 2;
    array->elems = 
        heapRealloc(float, array->elems, array->capacity);
}

/* ******************************************************************************** */

void* vgetBytes(struct varray *array){
    return (void*)array->elems;
}

/* ******************************************************************************** */

int vbyteSize(struct varray *array){
    return sizeof(float) * array->size;
}

/* ******************************************************************************** */

void insertFloat(struct varray *array, float value){
    if(array->size == array->capacity)
        vreserve(array);

    array->elems[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */

void insertPoint(struct varray *array, struct point point){
    insertFloat(array, point.position.x);
    insertFloat(array, point.position.y);
    insertFloat(array, point.position.z);
    insertFloat(array, point.position.w);
}

/* ******************************************************************************** */

void insertTriangle(struct varray *array, struct triangle triangle){
    insertPoint(array, triangle.point_a);
    insertPoint(array, triangle.point_b);
    insertPoint(array, triangle.point_c);
}

/* ******************************************************************************** */