#include "cvve/surface.h"

void create_surface(
    VkSurfaceKHR* surface, 
    VkInstance instance, 
    GLFWwindow* window
) {
    if (glfwCreateWindowSurface(instance, window, NULL, surface) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to create vulkan surface");
    }
}
void destroy_surface(
    VkSurfaceKHR surface,
    VkInstance instance
) {
    vkDestroySurfaceKHR(instance, surface, NULL);
}