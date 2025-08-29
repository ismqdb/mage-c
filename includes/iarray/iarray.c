/* ******************************************************************************** */

#include "./iarray.h"

/* ******************************************************************************** */

struct iarray icreateArray(){
    struct iarray array;

    array.size = 0;
    array.capacity = 16;
        
    array.elems = heapAllocSized(i32, array.capacity);
    array.elems[0] = '\0';

    return array;
}

/* ******************************************************************************** */

none idestroyArray(struct iarray *array){
    array->size = 0;
    free(array->elems);
}

/* ******************************************************************************** */

none ireserve(struct iarray *array){
    array->capacity *= 2;
    array->elems = 
        heapRealloc(i32, array->elems, array->capacity);
}

/* ******************************************************************************** */

none* igetBytes(struct iarray *array){
    return (none*)array->elems;
}

/* ******************************************************************************** */

i32 ibyteSize(struct iarray *array){
    return sizeof(i32) * array->size;
}

/* ******************************************************************************** */

none insertIndice(struct iarray *array, i32 value){
    if(array->size == array->capacity)
        ireserve(array);

    array->elems[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */