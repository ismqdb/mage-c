/* ******************************************************************************** */

#include "./array.h"

/* ******************************************************************************** */

struct array arrayCreate(enum arrayType t){
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

        case ARRAY_TYPE_MAT4:
            array.elems.m = heapAllocSized(struct mat4, array.capacity);
            break;
    }

    return array;
}

/* ******************************************************************************** */

struct array arrayFromRaw_i32(enum arrayType t, i32 *elems, i32 size){
    assert(t > ARRAY_TYPE_MIN && t < ARRAY_TYPE_MAX);

    struct array array = arrayCreate(t);

    while(array.capacity < size)
        arrayReserve(&array);

    memcpy(array.elems.i, elems, size*sizeof(i32));
    array.size = size;

    return array;
}

/* ******************************************************************************** */

struct array arrayFromRaw_f32(enum arrayType t, f32 *elems, i32 size){
    assert(t > ARRAY_TYPE_MIN && t < ARRAY_TYPE_MAX);

    struct array array = arrayCreate(t);

    while(array.capacity < size)
        arrayReserve(&array);

    memcpy(array.elems.f, elems, size*sizeof(f32));
    array.size = size;

    return array;
}

/* ******************************************************************************** */

none arrayDestroy(struct array *array){
    array->size = 0;

    switch(array->type){
        case ARRAY_TYPE_INT:
            free(array->elems.i);
            break;

        case ARRAY_TYPE_FLOAT:
            free(array->elems.f);
            break;

        case ARRAY_TYPE_MAT4:
            free(array->elems.m);
            break;
    }
}

/* ******************************************************************************** */

none arrayReserve(struct array *array){
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

        case ARRAY_TYPE_MAT4:
            array->elems.m =
                heapRealloc(struct mat4, array->elems.m, array->capacity);
            break;
    }
}

/* ******************************************************************************** */

none* arrayGetBytes(struct array *array){
    switch(array->type){
        case ARRAY_TYPE_INT:
            return (none*)array->elems.i;

        case ARRAY_TYPE_FLOAT:
            return (none*)array->elems.f;

        case ARRAY_TYPE_MAT4:
            return (none*)array->elems.m;
    }
}

/* ******************************************************************************** */

i32 arrayByteSize(struct array *array){
    switch(array->type){
        case ARRAY_TYPE_INT:
            return sizeof(i32) * array->size;

        case ARRAY_TYPE_FLOAT:
            return sizeof(f32) * array->size;

        case ARRAY_TYPE_MAT4:
            return sizeof(struct mat4) * array->size;
    }
}

/* ******************************************************************************** */

none arrayInsert_i32(struct array *array, i32 value){
    if(array->size == array->capacity)
        arrayReserve(array);

    array->elems.i[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */

none arrayInsert_f32(struct array *array, f32 value){
    if(array->size == array->capacity)
        arrayReserve(array);

    array->elems.f[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */

none arrayInsert_mat4(struct array *array, struct mat4 value){
    if(array->size == array->capacity)
        arrayReserve(array);

    array->elems.m[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */

none arrayFill_i32(struct array *array, i32 *ptr, i32 size){
    assert(array->type > ARRAY_TYPE_MIN && array->type < ARRAY_TYPE_MAX);
    memset(array->elems.i, *ptr, size*sizeof(i32));
}

/* ******************************************************************************** */

none arrayFill_f32(struct array *array, f32 *ptr, i32 size){
    assert(array->type > ARRAY_TYPE_MIN && array->type < ARRAY_TYPE_MAX);
    memset(array->elems.f, *ptr, size*sizeof(f32));
}

/* ******************************************************************************** */

struct array arrayMove(struct array *src){
    struct array dest = arrayCreate(src->type);

    while(dest.capacity < src->size)
        arrayReserve(&dest);

    switch(src->type){
        case ARRAY_TYPE_INT:
            dest = arrayFromRaw_i32(src->type, src->elems.i, src->size);
            break;

        case ARRAY_TYPE_FLOAT:
            dest = arrayFromRaw_f32(src->type, src->elems.f, src->size);
            break;
    }
    dest.size = src->size;

    arrayDestroy(src);

    return dest;
}

/* ******************************************************************************** */

struct array arrayCopy(struct array *src){
    struct array dest = arrayCreate(src->type);

    while(dest.capacity < src->size)
        arrayReserve(&dest);

    switch(src->type){
        case ARRAY_TYPE_INT:
            dest = arrayFromRaw_i32(src->type, src->elems.i, src->size);
            break;

        case ARRAY_TYPE_FLOAT:
            dest = arrayFromRaw_f32(src->type, src->elems.f, src->size);
            break;
    }
    dest.size = src->size;

    return dest;
}

/* ******************************************************************************** */

struct array arrayAppend(struct array *dest, struct array *src){
    assert(dest->type == src->type);

    while(dest->capacity < (dest->size+src->size))
        arrayReserve(dest);

    switch(src->type){
        case ARRAY_TYPE_INT:
            memcpy(&dest->elems.i[dest->size], src->elems.i, src->size*sizeof(i32));
            break;

        case ARRAY_TYPE_FLOAT:
            memcpy(&dest->elems.f[dest->size], src->elems.f, src->size*sizeof(f32));
            break;
    }
    dest->size += src->size;    
}

/* ******************************************************************************** */

none arrayPrint(struct array *array){
    switch(array->type){
        case ARRAY_TYPE_INT:
            for(i32 i = 0; i < array->size; i++)
                printf("%f ", array->elems.i[i]);
            break;

        case ARRAY_TYPE_FLOAT:
            for(i32 i = 0; i < array->size; i++)
                printf("%0.2f ", array->elems.f[i]);
            break;
    }
    putchar(10);
}

/* ******************************************************************************** */

none arrayInsert_vec4(struct array *array, struct vec4 vec){
    arrayInsert_f32(array, vec.x);
    arrayInsert_f32(array, vec.y);
    arrayInsert_f32(array, vec.z);
    arrayInsert_f32(array, vec.w);
}

/* ******************************************************************************** */

none arrayClear(struct array *array){
    *array = arrayCreate(array->type);
}

/* ******************************************************************************** */