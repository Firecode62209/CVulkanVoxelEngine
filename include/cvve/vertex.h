#ifndef CVVE_VERTEX_H
#define CVVE_VERTEX_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include "stb_ds.h"
#include "device.h"
#include "buffer.h"
#include "stdlib.h"

typedef struct Vertex {
    vec2 pos;
    vec3 color;
} Vertex;

extern const Vertex vertices[4];
extern const uint16_t indices[6];

VkVertexInputBindingDescription get_vertex_binding_description();
VkVertexInputAttributeDescription* get_attribute_descriptions();

void create_vertex_buffer(
    CvveBuffer* vertexBuffer, 
    CvveDevice device,
    VkCommandPool commandPool
);
void create_index_buffer(
    CvveBuffer* indexBuffer,
    CvveDevice device,
    VkCommandPool commandPool
);
#endif