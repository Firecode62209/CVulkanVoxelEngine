#ifndef CVVE_FRAME_BUFFERS_H
#define CVVE_FRAME_BUFFERS_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "device.h"
#include "swapchain.h"
#include "graphics_pipeline.h"

void create_frame_buffers(
    VkFramebuffer** framebuffers,
    CvveSwapchain swapchain,
    CvveGraphicsPipeline pipeline,
    CvveDevice device
);
void destroy_framebuffers(
    VkFramebuffer* framebuffers,
    CvveDevice device
);
void recreate_swapchain(
    CvveSwapchain* swapchain,
    VkFramebuffer** framebuffers,
    CvveGraphicsPipeline graphicsPipeline,
    CvveDevice device,
    VkSurfaceKHR surface,
    GLFWwindow* window
);

#endif