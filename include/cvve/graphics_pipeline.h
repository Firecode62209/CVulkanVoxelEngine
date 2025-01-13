#ifndef CVVE_GRAPHICS_PIPELINE_H
#define CVVE_GRAPHICS_PIPELINE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "file_reader.h"
#include "device.h"
#include "swapchain.h"
#include "shader.h"
#include "vertex.h"
#include "uniform.h"

typedef struct CvveGraphicsPipeline {
    VkPipeline data;
    VkPipelineLayout layout;
    VkRenderPass renderPass;
} CvveGraphicsPipeline;

void create_graphics_pipeline(
    CvveGraphicsPipeline* pipeline,
    CvveDescriptor descriptor,
    CvveDevice device,
    CvveSwapchain swapchain
);
void create_render_pass(
    VkRenderPass* renderPass,
    CvveDevice device,
    CvveSwapchain swapchain
);
VkShaderModule create_shader_module(
    CvveDevice device, 
    SpirVBinary bin
);
void destroy_graphics_pipeline(
    CvveGraphicsPipeline pipeline,
    CvveDevice device
);

#endif