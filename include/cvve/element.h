#ifndef CVVE_ELEMENT_H
#define CVVE_ELEMENT_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include "instance.h"
#include "surface.h"
#include "device.h"
#include "queue.h"
#include "swapchain.h"
#include "graphics_pipeline.h"
#include "frame_buffers.h"
#include "command.h"
#include "draw.h"
#include "vertex.h"

typedef struct CvveElement {
    VkInstance instance;
    VkSurfaceKHR surface;
    CvveDevice device;
    CvveSwapchain swapchain;
    CvveGraphicsPipeline graphicsPipeline;
    VkFramebuffer* framebuffers;
    CvveCommands commands;
    CvveSyncObjects* syncObjects;
    CvveBuffer vertexBuffer;
    CvveBuffer indexBuffer;
} CvveElement;

CvveElement create_cvve_element();
void init_cvve_element(
    CvveElement* element,
    GLFWwindow* window
);
void draw_element_frame(CvveElement* element, GLFWwindow* window);
void destroy_cvve_element(CvveElement element);
#endif