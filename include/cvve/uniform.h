#ifndef CVVE_UNIFORM_H
#define CVVE_UNIFORM_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include "device.h"
#include "buffer.h"
#include "time.h"

extern const int MAX_FRAMES_IN_FLIGHT;

typedef struct UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
} UniformBufferObject;

typedef struct CvveDescriptor {
    VkDescriptorPool pool;
    VkDescriptorSet* sets;
    VkDescriptorSetLayout setLayout;
} CvveDescriptor;

void create_descriptor_set_layout(
    CvveDescriptor* descriptor,
    CvveDevice device
);
void create_descriptor_pool(
    CvveDescriptor* descriptor,
    CvveDevice device
);
void create_descriptor_sets(
    CvveDescriptor* descriptor,
    CvveDevice device
);
void create_uniform_buffers(
    CvveBuffer** uniformBuffers,
    void*** uniformBuffersMapped,
    CvveDevice device
);
void update_uniform_buffer(
    void** uniformBuffersMapped,
    uint32_t currentImage,
    VkExtent2D extent
);
void destroy_uniform_buffers(
    CvveBuffer* uniformBuffers,
    CvveDevice device
);
void create_descriptor(
    CvveDescriptor* descriptor,
    CvveBuffer* uniformBuffers,
    CvveDevice device
);
void destroy_descriptor(
    CvveDescriptor descriptor,
    CvveDevice device
);
#endif