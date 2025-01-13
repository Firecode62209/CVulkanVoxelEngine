#include "cvve/element.h"

void init_cvve_element(
    CvveElement* element,
    GLFWwindow* window
) {
    create_instance(
        &element->instance
    );
    create_surface(
        &element->surface,
        element->instance,
        window
    );
    create_devices(
        &element->device,
        element->instance,
        element->surface
    );
    create_swapchain(
        &element->swapchain,
        element->device,
        element->surface,
        window
    );
    create_uniform_buffers(
        &element->uniformBuffers,
        &element->uniformBuffersMapped,
        element->device
    );
    create_descriptor(
        &element->descriptor,
        element->uniformBuffers,
        element->device
    );
    create_graphics_pipeline(
        &element->graphicsPipeline,
        element->descriptor,
        element->device,
        element->swapchain
    );
    create_frame_buffers(
        &element->framebuffers,
        element->swapchain,
        element->graphicsPipeline,
        element->device
    );
    create_commands(
        &element->commands,
        element->device,
        element->surface
    );
    create_vertex_buffer(
        &element->vertexBuffer,
        element->device,
        element->commands.pool
    );
    create_index_buffer(
        &element->indexBuffer,
        element->device,
        element->commands.pool
    );
    create_sync_objects(
        &element->syncObjects,
        element->device
    );
}

void draw_element_frame(CvveElement* element, GLFWwindow* window) {
    draw_frame(
        element->syncObjects,
        element->device,
        &element->swapchain,
        element->commands,
        element->graphicsPipeline,
        &element->framebuffers,
        element->surface,
        window,
        element->vertexBuffer,
        element->indexBuffer,
        element->uniformBuffersMapped,
        element->descriptor
    );
}

void destroy_cvve_element(CvveElement element) {
    destroy_sync_objects(element.syncObjects, element.device);
    destroy_commands(element.commands, element.device);
    destroy_framebuffers(element.framebuffers, element.device);
    destroy_graphics_pipeline(element.graphicsPipeline, element.device);
    destroy_swapchain(element.swapchain, element.device);
    destroy_descriptor(element.descriptor, element.device);
    destroy_uniform_buffers(element.uniformBuffers, element.device);
    destroy_buffer(element.vertexBuffer, element.device);
    destroy_buffer(element.indexBuffer, element.device);
    destroy_devices(element.device);
    destroy_surface(element.surface, element.instance);
    destroy_instance(element.instance);
}