#ifndef CVVE_SURFACE_H
#define CVVE_SURFACE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "instance.h"

void create_surface(
    VkSurfaceKHR* surface, 
    VkInstance instance, 
    GLFWwindow* window
);
void destroy_surface(
    VkSurfaceKHR surface,
    VkInstance instance
);

#endif