#include "cvve/frame_buffers.h"

void create_frame_buffers(
    VkFramebuffer** framebuffers,
    CvveSwapchain swapchain,
    CvveGraphicsPipeline pipeline,
    CvveDevice device
) {
    
    *framebuffers = NULL;
    arraddn(*framebuffers, arrlen(swapchain.imageViews));
    for (size_t i = 0; i < arrlen(swapchain.imageViews); i++) {
        VkImageView attachments[] = {
            swapchain.imageViews[i]
        };

        VkFramebufferCreateInfo framebufferInfo = {};
        framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebufferInfo.renderPass = pipeline.renderPass;
        framebufferInfo.attachmentCount = 1;
        framebufferInfo.pAttachments = attachments;
        framebufferInfo.width = swapchain.extent.width;
        framebufferInfo.height = swapchain.extent.height;
        framebufferInfo.layers = 1;

        if (vkCreateFramebuffer(device.logical, &framebufferInfo, NULL, &(*framebuffers)[i]) != VK_SUCCESS) {
            throw_verr(VERR_LEVEL_ERROR, "Failed to create vulkan framebuffer");
        }
    }
}
void destroy_framebuffers(
    VkFramebuffer* framebuffers,
    CvveDevice device
) {
    for (size_t i = 0; i < arrlen(framebuffers); i++) {
        vkDestroyFramebuffer(device.logical, framebuffers[i], NULL);
    }
}
void recreate_swapchain(
    CvveSwapchain* swapchain,
    VkFramebuffer** framebuffers,
    CvveGraphicsPipeline graphicsPipeline,
    CvveDevice device,
    VkSurfaceKHR surface,
    GLFWwindow* window
) {
    int width = 0, height = 0;
    glfwGetFramebufferSize(window, &width, &height);
    while (width == 0 || height == 0) {
        glfwGetFramebufferSize(window, &width, &height);
        glfwWaitEvents();
    }

    vkDeviceWaitIdle(device.logical);

    destroy_framebuffers(*framebuffers, device);
    destroy_swapchain(*swapchain, device);

    create_swapchain(swapchain, device, surface, window);
    create_frame_buffers(framebuffers, *swapchain, graphicsPipeline, device);
}