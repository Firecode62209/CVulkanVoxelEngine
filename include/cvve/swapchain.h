#ifndef CVVE_SWAPCHAIN_H
#define CVVE_SWAPCHAIN_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "stb_ds.h"
#include "v_err.h"
#include <math.h>
#include "queue.h"
#include "device.h"
#include "swapchain_support.h"

typedef struct CvveSwapchain {
    VkSwapchainKHR data;
    VkImage* images;
    VkImageView* imageViews;
    VkFormat imageFormat;
    VkExtent2D extent;
} CvveSwapchain;

SwapchainSupportDetails query_swapchain_support(
    VkPhysicalDevice device, 
    VkSurfaceKHR surface
);
VkSurfaceFormatKHR pick_surface_format(
    const VkSurfaceFormatKHR* availableFormats
);
VkPresentModeKHR pick_present_mode(
    const VkPresentModeKHR* availablePresentModes
);
VkExtent2D pick_swap_extent(
    const VkSurfaceCapabilitiesKHR* capabilities,
    GLFWwindow* window
);
void create_swapchain(
    CvveSwapchain* swapchain,
    CvveDevice device, 
    VkSurfaceKHR surface, 
    GLFWwindow* window
);
void create_image_views(
    CvveSwapchain* swapchain,
    CvveDevice device
);
void destroy_swapchain(
    CvveSwapchain swapchain,
    CvveDevice device
);
#endif