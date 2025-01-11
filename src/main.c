
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "app.h"
#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

int main(void) {
    if (!glfwInit())
        return -1;
    printf("GLFW initialized successfully!\n");

    
    VkApp* app = create_app();
    if (setjmp(VERR_ENVIORNMENT) == 0) {
        init_app(app);
        verr_log();
        run_app(app);
        destroy_app(app);
    }
    
    return verr_log();    
}