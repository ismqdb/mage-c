/* ******************************************************************************** */

#include "./array.h"

/* ******************************************************************************** */

struct array createArray(enum arrayType t){
    assert(t > ARRAY_TYPE_MIN && t < ARRAY_TYPE_MAX);

    struct array array;

    array.type = t;
    array.size = 0;
    array.capacity = 16;

    switch(array.type){
        case ARRAY_TYPE_INT:
            array.elems.i = heapAllocSized(i32, array.capacity);
            array.elems.i[0] = '\0';
            break;

        case ARRAY_TYPE_FLOAT:
            array.elems.f = heapAllocSized(f32, array.capacity);
            array.elems.f[0] = '\0';
            break;
    }

    return array;
}

/* ******************************************************************************** */

none destroyArray(struct array *array){
    array->size = 0;

    switch(array->type){
        case ARRAY_TYPE_INT:
            free(array->elems.i);
            break;

        case ARRAY_TYPE_FLOAT:
            free(array->elems.f);
            break;
    }
}

/* ******************************************************************************** */

none reserve(struct array *array){
    array->capacity *= 2;

    switch(array->type){
        case ARRAY_TYPE_INT:
            array->elems.i = 
                heapRealloc(i32, array->elems.i, array->capacity);
            break;

        case ARRAY_TYPE_FLOAT:
            array->elems.f = 
                heapRealloc(f32, array->elems.f, array->capacity);
            break;
    }
}

/* ******************************************************************************** */

none* getBytes(struct array *array){
    switch(array->type){
        case ARRAY_TYPE_INT:
            return (none*)array->elems.i;

        case ARRAY_TYPE_FLOAT:
            return (none*)array->elems.f;
    }
}

/* ******************************************************************************** */

i32 byteSize(struct array *array){
    switch(array->type){
        case ARRAY_TYPE_INT:
            return sizeof(i32) * array->size;

        case ARRAY_TYPE_FLOAT:
            return sizeof(f32) * array->size;
    }
}

/* ******************************************************************************** */

none insertIndice(struct array *array, i32 value){
    if(array->size == array->capacity)
        reserve(array);

    array->elems.i[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */

none insertFloat(struct array *array, f32 value){
    if(array->size == array->capacity)
        reserve(array);

    array->elems.f[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */

none insertVec4(struct array *array, struct vec4 vec){
    insertFloat(array, vec.x);
    insertFloat(array, vec.y);
    insertFloat(array, vec.z);
    insertFloat(array, vec.w);
}

/* ******************************************************************************** */