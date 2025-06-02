/* ******************************************************************************** */

#include "./array.h"

/* ******************************************************************************** */

struct array createArray(enum arrayType type){
    assert(type > ARRAY_TYPE_MIN);
    assert(type < ARRAY_TYPE_MAX);

    struct array array;

    array.size = 0;
    array.capacity = 16;
    array.type = type;
    
    switch(type){
        case ARRAY_INT:
            array.data.ints = heapAllocSized(int, array.capacity);
            array.data.ints[0] = '\0';
        break;

        case ARRAY_FLOAT:
            array.data.floats = heapAllocSized(float, array.capacity);
            array.data.floats[0] = '\0';
        break;
    }

    return array;
}

/* ******************************************************************************** */

void destroyArray(struct array *array){
    array->size = 0;

    switch(array->type){
        case ARRAY_INT:
            free(array->data.ints);
        break;

        case ARRAY_FLOAT:
            free(array->data.floats);
        break;
    }
}

/* ******************************************************************************** */

void reserve(struct array *array){
    switch(array->type){
        case ARRAY_INT:
            array->capacity *= 2;
            array->data.ints = 
                heapRealloc(int, array->data.ints, array->capacity);
        break;

        case ARRAY_FLOAT:
            array->capacity *= 2;
            array->data.ints = 
                heapRealloc(int, array->data.ints, array->capacity);
        break;
    }
}

/* ******************************************************************************** */

void* getBytes(struct array *array){
    switch(array->type){
        case ARRAY_INT:
            return (void*)array->data.ints;

        case ARRAY_FLOAT:
            return (void*)array->data.floats;
    }
}

/* ******************************************************************************** */

int byteSize(struct array *array){
    switch(array->type){
        case ARRAY_INT:
            return sizeof(int) * array->size;

        case ARRAY_FLOAT:
            return sizeof(float) * array->size;
    }
}

/* ******************************************************************************** */

int insertInt(struct array *array, int value){
    if(array->size == array->capacity)
        reserve(array);

    array->data.ints[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */

void insertFloat(struct array *array, float value){
    if(array->size == array->capacity)
        reserve(array);

    array->data.floats[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */