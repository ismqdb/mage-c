/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

struct appInfo {
    u8 title[128];
    i32 windowWidth;
    i32 windowHeight;
    i32 majorVersion;
    i32 minorVersion;
    i32 samples;
    union {
        struct {
            u32    fullscreen  : 1;
            u32    vsync       : 1;
            u32    cursor      : 1;
            u32    stereo      : 1;
            u32    debug       : 1;
            u32    robust      : 1;
        };
        u32        all;
    } flags;
};

/* ******************************************************************************** */