#include "cvve/draw.h"

const int MAX_FRAMES_IN_FLIGHT = 2;
uint32_t currentFrame = 0;
bool framebufferResized = false;

void create_sync_objects(
    CvveSyncObjects** syncObjects,
    CvveDevice device
) {
    *syncObjects = NULL;
    arraddn(*syncObjects, MAX_FRAMES_IN_FLIGHT);

    VkSemaphoreCreateInfo semaphoreInfo = {};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkFenceCreateInfo fenceInfo = {};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        if (vkCreateSemaphore(device.logical, &semaphoreInfo, NULL, &(*syncObjects)[i].imageAvailableSemaphore) != VK_SUCCESS ||
        vkCreateSemaphore(device.logical, &semaphoreInfo, NULL, &(*syncObjects)[i].renderFinishedSemaphore) != VK_SUCCESS ||
        vkCreateFence(device.logical, &fenceInfo, NULL, &(*syncObjects)[i].inFlightFence) != VK_SUCCESS ) {
            throw_verr(VERR_LEVEL_ERROR, "Failed to create sync objects");
        };
    }
    
}

void destroy_sync_objects(
    CvveSyncObjects* syncObjects,
    CvveDevice device
) {
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        vkDestroySemaphore(device.logical, syncObjects[i].imageAvailableSemaphore, NULL);
        vkDestroySemaphore(device.logical, syncObjects[i].renderFinishedSemaphore, NULL);
        vkDestroyFence(device.logical, syncObjects[i].inFlightFence, NULL);
    }
}

void draw_frame(
    CvveSyncObjects* syncObjects,
    CvveDevice device,
    CvveSwapchain* swapchain,
    CvveCommands commands,
    CvveGraphicsPipeline graphicsPipeline,
    VkFramebuffer** framebuffers,
    VkSurfaceKHR surface,
    GLFWwindow* window,
    CvveBuffer vertexBuffer,
    CvveBuffer indexBuffer
) {
    vkWaitForFences(device.logical, 1, &syncObjects[currentFrame].inFlightFence, VK_TRUE, UINT64_MAX);

    uint32_t imageIndex;
    VkResult result = vkAcquireNextImageKHR(device.logical, (*swapchain).data, UINT64_MAX, syncObjects[currentFrame].imageAvailableSemaphore, VK_NULL_HANDLE, &imageIndex);
    
    if (result == VK_ERROR_OUT_OF_DATE_KHR || framebufferResized) {
        framebufferResized = false;
        recreate_swapchain(swapchain, framebuffers, graphicsPipeline, device, surface, window);
        return;
    } else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to acquire vulkan swapchain image");
    }

    vkResetFences(device.logical, 1, &syncObjects[currentFrame].inFlightFence);

    vkResetCommandBuffer(commands.buffers[currentFrame], 0);
    record_command_buffer(
        commands.buffers[currentFrame],
        imageIndex,
        graphicsPipeline,
        *framebuffers,
        *swapchain,
        vertexBuffer,
        indexBuffer
    );

    VkSubmitInfo submitInfo = {};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore waitSemaphores[] = {syncObjects[currentFrame].imageAvailableSemaphore};
    VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = waitSemaphores;
    submitInfo.pWaitDstStageMask = waitStages;
    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &commands.buffers[currentFrame];

    VkSemaphore signalSemaphores[] = {syncObjects[currentFrame].renderFinishedSemaphore};
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores = signalSemaphores;

    if (vkQueueSubmit(device.queues.graphics, 1, &submitInfo, syncObjects[currentFrame].inFlightFence) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "failed to submit draw command buffer");
    }

    VkPresentInfoKHR presentInfo = {};
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = signalSemaphores;

    VkSwapchainKHR swapchains[] = {(*swapchain).data};
    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = swapchains;
    presentInfo.pImageIndices = &imageIndex;
    presentInfo.pResults = NULL;

    vkQueuePresentKHR(device.queues.present, &presentInfo);

    currentFrame = (currentFrame + 1) % MAX_FRAMES_IN_FLIGHT;
}