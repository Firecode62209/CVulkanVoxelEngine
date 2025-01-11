#include "app.h"
const uint32_t WINDOW_WIDTH = 800;
const uint32_t WINDOW_HEIGHT = 600;

struct VkApp {
    GLFWwindow* window;
    CvveElement element;
};

VkApp* create_app() {
    VkApp* app = malloc(sizeof(VkApp));
    return app;
}

void init_app(VkApp* app) {
    init_window(app);
    init_cvve_element(&app->element, app->window);
}

void init_window(VkApp* app) {
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    app->window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "VK WINDOW", NULL, NULL);
    if (app->window == NULL) throw_verr(VERR_LEVEL_ERROR, "Failed to create GLFW window");
    glfwSetFramebufferSizeCallback(app->window, (GLFWframebuffersizefun)framebufferResizeCallback);
}

void run_app(VkApp* app) {
    while (!glfwWindowShouldClose(app->window)) {
        glfwPollEvents();
        draw_element_frame(&app->element, app->window);
    }

    vkDeviceWaitIdle(app->element.device.logical);
}

void destroy_app(VkApp* app) {
    destroy_cvve_element(app->element);
    free(app);
}

static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    framebufferResized = true;
}