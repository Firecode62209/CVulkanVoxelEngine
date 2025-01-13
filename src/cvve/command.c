#include "cvve/command.h"

void create_command_pool(
    CvveCommands* commands,
    CvveDevice device,
    VkSurfaceKHR surface
) {
    QueueFamilyIndices queueFamilyIndices = find_queue_families(device.physical, surface);

    VkCommandPoolCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    createInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    createInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily;
    
    if (vkCreateCommandPool(device.logical, &createInfo, NULL, &commands->pool) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to create vulka command pool");
    }
}

void create_commands(
    CvveCommands* commands,
    CvveDevice device,
    VkSurfaceKHR surface
) {
    create_command_pool(commands, device, surface);
    commands->buffers = NULL;
    arraddn(commands->buffers, MAX_FRAMES_IN_FLIGHT);

    VkCommandBufferAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.commandPool = commands->pool;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandBufferCount = arrlen(commands->buffers);

    if (vkAllocateCommandBuffers(device.logical, &allocInfo, commands->buffers) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to allocate vulkan command buffer");
    }
}

void record_command_buffer(
    VkCommandBuffer buffer,
    uint32_t imageIndex,
    CvveGraphicsPipeline graphicsPipeline,
    VkFramebuffer* framebuffers,
    CvveSwapchain swapchain,
    CvveBuffer vertexBuffer,
    CvveBuffer indexBuffer,
    CvveDescriptor descriptor
) {
    VkCommandBufferBeginInfo beginInfo = {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = 0;
    beginInfo.pInheritanceInfo = NULL;

    if (vkBeginCommandBuffer(buffer, &beginInfo) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to begin recording vulkan command buffer");
    }

    VkRenderPassBeginInfo renderPassInfo = {};
    renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPassInfo.renderPass = graphicsPipeline.renderPass;
    renderPassInfo.framebuffer = framebuffers[imageIndex];
    VkOffset2D offset = {0, 0};
    renderPassInfo.renderArea.offset = offset;
    renderPassInfo.renderArea.extent = swapchain.extent;
    VkClearValue clearColor = {{{0.0f, 0.0f, 0.0f, 1.0f}}};
    renderPassInfo.clearValueCount = 1;
    renderPassInfo.pClearValues = &clearColor;

    vkCmdBeginRenderPass(buffer, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
    vkCmdBindPipeline(buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, graphicsPipeline.data);

    VkBuffer vertexBuffers[] = {vertexBuffer.data};
    VkDeviceSize offsets[] = {0};
    vkCmdBindVertexBuffers(buffer, 0, 1, vertexBuffers, offsets);
    vkCmdBindIndexBuffer(buffer, indexBuffer.data, 0, VK_INDEX_TYPE_UINT16);

    VkViewport viewport = {};
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = (float)swapchain.extent.width;
    viewport.height = (float)swapchain.extent.height;
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;
    vkCmdSetViewport(buffer, 0, 1, &viewport);

    VkRect2D scissor = {};
    scissor.offset = offset;
    scissor.extent = swapchain.extent;
    vkCmdSetScissor(buffer, 0, 1, &scissor);

    vkCmdBindDescriptorSets(buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, graphicsPipeline.layout, 0, 1, &descriptor.sets[currentFrame], 0, NULL);
    vkCmdDrawIndexed(buffer, sizeof(indices)/sizeof(indices[0]), 1, 0, 0, 0);
    vkCmdEndRenderPass(buffer);

    if (vkEndCommandBuffer(buffer) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to record vulkan command buffer");
    }
}
void destroy_commands(
    CvveCommands commands,
    CvveDevice device
) {
    vkDestroyCommandPool(device.logical, commands.pool, NULL);
}