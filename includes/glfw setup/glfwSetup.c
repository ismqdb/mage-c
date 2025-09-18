/* ******************************************************************************** */

#include "./glfwSetup.h"

/* ******************************************************************************** */

struct appInfo info;
GLFWwindow* window;

i32 pressed[GLFW_KEY_LAST];

/* ******************************************************************************** */

none onResize(GLFWwindow* window, i32 w, i32 h){
    info.windowWidth = w;
    info.windowHeight = h;

    glViewport(0, 0, info.windowWidth, info.windowHeight);
}

/* ******************************************************************************** */

none onKey(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods){
    if(key == GLFW_KEY_UNKNOWN)
        return;

    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, 1);
    
    for(i32 i = 0; i < GLFW_KEY_LAST; i++)
        if(action == GLFW_PRESS && i == key)
            pressed[key] = 1;
        else if(action == GLFW_RELEASE && i == key)
            pressed[key] = 0;
}

/* ******************************************************************************** */

none onMouseButton(GLFWwindow* window, i32 button, i32 action, i32 mods){}
none onMouseMove(GLFWwindow* window, f64 x, f64 y){}
none onMouseWheel(GLFWwindow* window, f64 xoffset, f64 yoffset){}

/* ******************************************************************************** */

none setVsync(i32 enable){
    info.flags.vsync = enable ? 1 : 0;
    glfwSwapInterval((i32)info.flags.vsync);
}

/* ******************************************************************************** */

none getMousePosition(i32 *x, i32 *y){
    f64 dx, dy;
    glfwGetCursorPos(window, &dx, &dy);

    *x = (i32)(floor(dx));
    *y = (i32)(floor(dy));
}

/* ******************************************************************************** */

none glfwSetup(){
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);

    if (!glfwInit()) {
        const char* description;
        i32 code = glfwGetError(&description);
        printf("GLFW init failed (%d): %s\n", code, description);
        abort();
    }

    info.windowWidth = 1920;
    info.windowHeight = 1080;

    const char title[] = "MAGE";
    memcpy(info.title, title, sizeof(title));
    
    #ifdef __APPLE__
        info.majorVersion = 3;
        info.minorVersion = 2;
    #else
        info.majorVersion = 4;
        info.minorVersion = 3;
    #endif

    info.samples = 0;
    info.flags.all = 0;
    info.flags.cursor = 1;

    #ifdef _DEBUG
        info.flags.debug = 1;
    #endif

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(info.windowWidth, info.windowHeight, info.title, 
        info.flags.fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);

    glfwMakeContextCurrent(window);

    glfwSetWindowSizeCallback(window, onResize);
    glfwSetKeyCallback(window, onKey);
    glfwSetMouseButtonCallback(window, onMouseButton);
    glfwSetCursorPosCallback(window, onMouseMove);
    glfwSetScrollCallback(window, onMouseWheel);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glfwSetKeyCallback(window, onKey);
}

/* ******************************************************************************** */

none glfwTeardown(){
    glfwDestroyWindow(window);
    glfwTerminate();
}

/* ******************************************************************************** */