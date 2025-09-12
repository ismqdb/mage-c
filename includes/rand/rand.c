/* ******************************************************************************** */

#include "rand.h"

/* ******************************************************************************** */

i32 igetRand(i32 lo, i32 hi){
    assert(lo < hi);

    srand(time(NULL));

    return lo + rand() % (hi-lo+1);
}

/* ******************************************************************************** */

f32 fgetRand(f32 lo, f32 hi){
    i32 urandom = open("/dev/urandom", O_RDONLY);
    if (urandom < 0) {
        perror("open");
        exit(1);
    }

    u32 result;
    read(urandom, &result, sizeof(result));
    close(urandom);

    f32 scale = result / (f32) UINT_MAX;
    return lo + scale * (hi - lo);
}

/* ******************************************************************************** */