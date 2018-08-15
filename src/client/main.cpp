#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "flextGL.h"
#define SOKOL_IMPL
#define SOKOL_GLCORE33
#include "sokol_gfx.h"

const int WIDTH = 640;
const int HEIGHT = 480;

#if defined(WIN32)
int __stdcall WinMain(void*, void*,char* cmdLine,  int cmdShow) {
#else
int main(int argc, char* argv[]) {
#endif
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* w = glfwCreateWindow(WIDTH, HEIGHT, "GLFW:Clear", 0, 0);
    glfwMakeContextCurrent(w);
    glfwSwapInterval(1);
    flextInit();
     
    sg_desc desc = { 0 };
    sg_setup(&desc);
    assert(sg_isvalid());

    sg_pass_action pass_action{};
    sg_color_attachment_action clear = { SG_ACTION_CLEAR, {0.1f, 0.2f, 0.5f, 1.0f} };
    pass_action.colors[0] = clear;

    while (!glfwWindowShouldClose(w)) {
        float g = (float)(pass_action.colors[0].val[1] + 0.01);
        if (g > 1.0f) g = 0.0f;
        pass_action.colors[0].val[1] = g;

        int cur_width, cur_height;
        glfwGetFramebufferSize(w, &cur_width, &cur_height);
        sg_begin_default_pass(&pass_action, cur_width, cur_height);
        sg_end_pass();
        sg_commit();
        glfwSwapBuffers(w);
        glfwPollEvents();
    }

    sg_shutdown();
    glfwTerminate();

    return 0;
}