#include "cvve/buffer.h"

uint32_t find_memory_type(CvveDevice device, uint32_t typeFilter, VkMemoryPropertyFlags properties) {
    VkPhysicalDeviceMemoryProperties memProps;
    vkGetPhysicalDeviceMemoryProperties(device.physical, &memProps);

    for (uint32_t i = 0; i < memProps.memoryTypeCount; i++) {
        if (typeFilter & (1 << i) && (memProps.memoryTypes[i].propertyFlags & properties) == properties) {
            return i;
        }
    }

    throw_verr(VERR_LEVEL_ERROR, "Failed to find suitable memory type");
    return 0;
}

void create_buffer(
    CvveBuffer* buffer,
    VkDeviceSize size,
    VkBufferUsageFlags usage,
    VkMemoryPropertyFlags properties,
    CvveDevice device
) {
    VkBufferCreateInfo bufferInfo = {};
    bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferInfo.size = size;
    bufferInfo.usage = usage;
    bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    if (vkCreateBuffer(device.logical, &bufferInfo, NULL, &buffer->data) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to create buffer");
    }

    VkMemoryRequirements memRquirements;
    vkGetBufferMemoryRequirements(device.logical, buffer->data, &memRquirements);

    VkMemoryAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memRquirements.size;
    allocInfo.memoryTypeIndex = find_memory_type(device, memRquirements.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

    if (vkAllocateMemory(device.logical, &allocInfo, NULL, &buffer->memory) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to allocate buffer memory");
    }

    vkBindBufferMemory(device.logical, buffer->data, buffer->memory, 0);
}

void copy_buffer(
    CvveBuffer src,
    CvveBuffer dst,
    VkDeviceSize size,
    VkCommandPool commandPool,
    CvveDevice device
) {
    VkCommandBufferAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandPool = commandPool;
    allocInfo.commandBufferCount = 1;

    VkCommandBuffer commandBuffer;
    vkAllocateCommandBuffers(device.logical, &allocInfo, &commandBuffer);
    
    VkCommandBufferBeginInfo beginInfo = {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

    vkBeginCommandBuffer(commandBuffer, &beginInfo);

    VkBufferCopy copyRegion = {};
    copyRegion.srcOffset = 0;
    copyRegion.dstOffset = 0;
    copyRegion.size = size;
    vkCmdCopyBuffer(commandBuffer, src.data, dst.data, 1, &copyRegion);
    vkEndCommandBuffer(commandBuffer);

    VkSubmitInfo submitInfo = {};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &commandBuffer;

    vkQueueSubmit(device.queues.graphics, 1, &submitInfo, VK_NULL_HANDLE);
    vkQueueWaitIdle(device.queues.graphics);

    vkFreeCommandBuffers(device.logical, commandPool, 1, &commandBuffer);
}

void destroy_buffer(
    CvveBuffer buffer, 
    CvveDevice device
) {
    vkDestroyBuffer(device.logical, buffer.data, NULL);
    vkFreeMemory(device.logical, buffer.memory, NULL);
}