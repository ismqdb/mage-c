/* ******************************************************************************** */

#include "./farray.h"

/* ******************************************************************************** */

struct farray fcreateArray(){
    struct farray array;

    array.size = 0;
    array.capacity = 16;
    
    array.elems = heapAllocSized(f32, array.capacity);
    array.elems[0] = '\0';

    return array;
}

/* ******************************************************************************** */

void fdestroyArray(struct farray *array){
    array->size = 0;
    free(array->elems);
}

/* ******************************************************************************** */

void freserve(struct farray *array){
    array->capacity *= 2;
    array->elems = 
        heapRealloc(f32, array->elems, array->capacity);
}

/* ******************************************************************************** */

void* fgetBytes(struct farray *array){
    return (void*)array->elems;
}

/* ******************************************************************************** */

i32 fbyteSize(struct farray *array){
    return sizeof(f32) * array->size;
}

/* ******************************************************************************** */

void insertFloat(struct farray *array, f32 value){
    if(array->size == array->capacity)
        freserve(array);

    array->elems[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */

void insertPoint(struct farray *array, struct point point){
    insertFloat(array, point.position.x);
    insertFloat(array, point.position.y);
    insertFloat(array, point.position.z);
    insertFloat(array, point.position.w);
}

/* ******************************************************************************** */