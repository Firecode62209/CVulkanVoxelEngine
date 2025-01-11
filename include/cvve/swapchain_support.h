#ifndef CVVE_SWAPCHAIN_SUPPORT_H
#define CVVE_SWAPCHAIN_SUPPORT_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

typedef struct SwapchainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    VkSurfaceFormatKHR* formats;
    VkPresentModeKHR* presentModes;
} SwapchainSupportDetails;
SwapchainSupportDetails query_swapchain_support(
    VkPhysicalDevice device,
    VkSurfaceKHR surface
);

#endif