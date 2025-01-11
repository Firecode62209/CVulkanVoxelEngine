#ifndef CVVE_QUEUE_H
#define CVVE_QUEUE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct CvveQueues {
    VkQueue graphics;
    VkQueue present;
} CvveQueues;

typedef struct QueueFamilyIndices {
    bool hasGraphicsValue;
    bool hasPresentValue;
    uint32_t graphicsFamily;
    uint32_t presentFamily;
} QueueFamilyIndices;

QueueFamilyIndices find_queue_families(
    VkPhysicalDevice physicalDevice,
    VkSurfaceKHR surface
);
bool queue_has_support(
    QueueFamilyIndices* indices
);
#endif