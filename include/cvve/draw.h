#ifndef CVVE_DRAW_H
#define CVVE_DRAW_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "device.h"
#include "swapchain.h"
#include "command.h"
#include "graphics_pipeline.h"
#include "frame_buffers.h"
#include "vertex.h"
#include "uniform.h"

extern const int MAX_FRAMES_IN_FLIGHT;
extern uint32_t currentFrame;
extern bool framebufferResized;

typedef struct CvveSyncObjects {
    VkSemaphore imageAvailableSemaphore;
    VkSemaphore renderFinishedSemaphore;
    VkFence inFlightFence;
} CvveSyncObjects;
void create_sync_objects(
    CvveSyncObjects** syncObjects,
    CvveDevice device
);
void destroy_sync_objects(
    CvveSyncObjects* syncObjects,
    CvveDevice device
);
void draw_frame(
    CvveSyncObjects* syncObjects,
    CvveDevice device,
    CvveSwapchain* swapchain,
    CvveCommands commands,
    CvveGraphicsPipeline graphicsPipeline,
    VkFramebuffer** framebuffers,
    VkSurfaceKHR surface,
    GLFWwindow* window,
    CvveBuffer vertexBuffer,
    CvveBuffer indexBuffer,
    void** uniformBuffersMapped,
    CvveDescriptor descriptor
);

#endif