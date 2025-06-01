/* ******************************************************************************** */

#define heapAllocSized(type, size) ((type*)malloc(size*sizeof(type)))
#define heapAllocArray(type, size) ((type**)malloc(size*sizeof(type)))

#define heapRealloc(type, data, size) (data = (type*)realloc(data, size*sizeof(type)))
    
#define heapArrayRealloc(type, data, size) (data = (type*)realloc(data, size*sizeof(type)))

/* ******************************************************************************** */