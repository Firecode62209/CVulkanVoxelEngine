#ifndef CVVE_BUFFER_H
#define CVVE_BUFFER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include "device.h"

typedef struct CvveBuffer {
    VkBuffer data;
    VkDeviceMemory memory;
} CvveBuffer;

void create_buffer(
    CvveBuffer* buffer, 
    VkDeviceSize size,
    VkBufferUsageFlags usage,
    VkMemoryPropertyFlags properties,
    CvveDevice device
);
void copy_buffer(
    CvveBuffer src,
    CvveBuffer dst,
    VkDeviceSize size,
    VkCommandPool commandPool,
    CvveDevice device
);
void destroy_buffer(
    CvveBuffer buffer, 
    CvveDevice device
);
uint32_t find_memory_type(
    CvveDevice device, 
    uint32_t typeFilter, 
    VkMemoryPropertyFlags properties
);


#endif