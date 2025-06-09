/* ******************************************************************************** */

#include "./iarray.h"

/* ******************************************************************************** */

struct iarray icreateArray(){
    struct iarray array;

    array.size = 0;
    array.capacity = 16;
        
    array.elems = heapAllocSized(int, array.capacity);
    array.elems[0] = '\0';

    return array;
}

/* ******************************************************************************** */

void idestroyArray(struct iarray *array){
    array->size = 0;
    free(array->elems);
}

/* ******************************************************************************** */

void ireserve(struct iarray *array){
    array->capacity *= 2;
    array->elems = 
        heapRealloc(int, array->elems, array->capacity);
}

/* ******************************************************************************** */

void* igetBytes(struct iarray *array){
    return (void*)array->elems;
}

/* ******************************************************************************** */

int ibyteSize(struct iarray *array){
    return sizeof(int) * array->size;
}

/* ******************************************************************************** */

int insertInt(struct iarray *array, int value){
    if(array->size == array->capacity)
        ireserve(array);

    array->elems[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */

void insertIndice(struct iarray *array, int indice){
    insertInt(array, indice);
}

/* ******************************************************************************** */