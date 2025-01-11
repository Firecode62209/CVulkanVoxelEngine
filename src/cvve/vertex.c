#include "cvve/vertex.h"

const Vertex vertices[4] = {
    {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
    {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
    {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
    {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}
};
const uint16_t indices[6] = {
    0, 1, 2, 2, 3, 0
};

VkVertexInputBindingDescription get_vertex_binding_description() {
    VkVertexInputBindingDescription bindingDescription = {};
    bindingDescription.binding = 0;
    bindingDescription.stride = sizeof(Vertex);
    bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

    return bindingDescription;
}

VkVertexInputAttributeDescription* get_attribute_descriptions() {
    VkVertexInputAttributeDescription* attributesDescriptions = NULL;
    for(int i = 0; i < 2; i++) {
        VkVertexInputAttributeDescription desc = {};
        arrpush(attributesDescriptions, desc);
    }
    attributesDescriptions[0].binding = 0;
    attributesDescriptions[0].location = 0;
    attributesDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
    attributesDescriptions[0].offset = offsetof(Vertex, pos);

    attributesDescriptions[1].binding = 0;
    attributesDescriptions[1].location = 1;
    attributesDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
    attributesDescriptions[1].offset = offsetof(Vertex, color);

    return attributesDescriptions;
}

void create_vertex_buffer(
    CvveBuffer* vertexBuffer, 
    CvveDevice device,
    VkCommandPool commandPool
) {
    VkDeviceSize bufferSize = sizeof(vertices);

    CvveBuffer stagingBuffer;
    create_buffer(&stagingBuffer, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
    device);

    void* data;
    vkMapMemory(device.logical, stagingBuffer.memory, 0, bufferSize, 0, &data);
    memcpy(data, vertices, (size_t) bufferSize);
    vkUnmapMemory(device.logical, stagingBuffer.memory);

    create_buffer(vertexBuffer, bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
    device);

    copy_buffer(stagingBuffer, *vertexBuffer, bufferSize, commandPool, device);
    destroy_buffer(stagingBuffer, device);
}

void create_index_buffer(
    CvveBuffer* indexBuffer,
    CvveDevice device,
    VkCommandPool commandPool
) {
    VkDeviceSize bufferSize = sizeof(indices);

    CvveBuffer stagingBuffer;
    create_buffer(&stagingBuffer, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
    device);

    void* data;
    vkMapMemory(device.logical, stagingBuffer.memory, 0, bufferSize, 0, &data);
    memcpy(data, indices, (size_t) bufferSize);
    vkUnmapMemory(device.logical, stagingBuffer.memory);

    create_buffer(indexBuffer, bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
    device);

    copy_buffer(stagingBuffer, *indexBuffer, bufferSize, commandPool, device);
    destroy_buffer(stagingBuffer, device);
}