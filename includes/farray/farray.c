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

none fdestroyArray(struct farray *array){
    array->size = 0;
    free(array->elems);
}

/* ******************************************************************************** */

none freserve(struct farray *array){
    array->capacity *= 2;
    array->elems = 
        heapRealloc(f32, array->elems, array->capacity);
}

/* ******************************************************************************** */

none* fgetBytes(struct farray *array){
    return (none*)array->elems;
}

/* ******************************************************************************** */

i32 fbyteSize(struct farray *array){
    return sizeof(f32) * array->size;
}

/* ******************************************************************************** */

none insertFloat(struct farray *array, f32 value){
    if(array->size == array->capacity)
        freserve(array);

    array->elems[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */

none insertVec4(struct farray *array, struct vec4 vec){
    insertFloat(array, vec.x);
    insertFloat(array, vec.y);
    insertFloat(array, vec.z);
    insertFloat(array, vec.w);
}

/* ******************************************************************************** */