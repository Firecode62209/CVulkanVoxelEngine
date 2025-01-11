#ifndef CVVE_COMMAND_H
#define CVVE_COMMAND_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "device.h"
#include "queue.h"
#include "graphics_pipeline.h"
#include "swapchain.h"
#include "vertex.h"

extern const int MAX_FRAMES_IN_FLIGHT;

typedef struct CvveCommands {
    VkCommandPool pool;
    VkCommandBuffer* buffers;
} CvveCommands;

void create_command_pool(
    CvveCommands* commands,
    CvveDevice device,
    VkSurfaceKHR surface
);
void create_commands(
    CvveCommands* commands,
    CvveDevice device,
    VkSurfaceKHR surface
);
void record_command_buffer(
    VkCommandBuffer buffer,
    uint32_t imageIndex,
    CvveGraphicsPipeline graphicsPipeline,
    VkFramebuffer* framebuffers,
    CvveSwapchain swapchain,
    CvveBuffer vertexBuffer,
    CvveBuffer indexBuffer
);
void destroy_commands(
    CvveCommands commands,
    CvveDevice device
);

#endif