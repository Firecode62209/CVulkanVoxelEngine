#include "cvve/swapchain.h"

SwapchainSupportDetails query_swapchain_support(
    VkPhysicalDevice device, 
    VkSurfaceKHR surface
) {
    SwapchainSupportDetails details;
    details.formats = NULL;
    details.presentModes = NULL;
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, surface, &details.capabilities);

    uint32_t formatCount = 0;
    vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, NULL);
    if (formatCount != 0) {
        arraddn(details.formats, formatCount);
        vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount,  details.formats);
    }

    uint32_t presentModeCount = 0;
    vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentModeCount, NULL);
    if (presentModeCount != 0) {
        arraddn(details.presentModes, presentModeCount);
        vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentModeCount,  details.presentModes);
    }

    return details;
}

VkSurfaceFormatKHR pick_surface_format(
    const VkSurfaceFormatKHR* availableFormats
) {
    for(int i = 0; i < arrlen(availableFormats); i++) {
        if (availableFormats[i].format == VK_FORMAT_B8G8R8_SRGB && 
        availableFormats[i].colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
            return availableFormats[i];
        }
    }

    return availableFormats[0];
}

VkPresentModeKHR pick_present_mode(
    const VkPresentModeKHR* availablePresentModes
) {
    for(int i = 0; i < arrlen(availablePresentModes); i++) {
        if (availablePresentModes[i] == VK_PRESENT_MODE_MAILBOX_KHR) {
            throw_verr(VERR_LEVEL_INFO, "Swap chain present mode set to MAILBOX");
            return availablePresentModes[i];
        }
    }
    throw_verr(VERR_LEVEL_INFO, "Swap chain present mode set to FIFO");
    return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D pick_swap_extent(
    const VkSurfaceCapabilitiesKHR* capabilities,
    GLFWwindow* window
) {
    if (capabilities->currentExtent.width != UINT32_MAX) {
        return capabilities->currentExtent;
    } else {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        VkExtent2D actualExtent = { width, height };

        actualExtent.width = fmin(capabilities->maxImageExtent.width, fmax(actualExtent.width, capabilities->minImageExtent.width));
        actualExtent.height = fmin(capabilities->maxImageExtent.height,fmax(actualExtent.height, capabilities->minImageExtent.height));
        
        return actualExtent;
    }
}

void create_swapchain(
    CvveSwapchain* swapchain,
    CvveDevice device, 
    VkSurfaceKHR surface, 
    GLFWwindow* window
) {
    SwapchainSupportDetails swapchainSupport = query_swapchain_support(device.physical, surface);

    VkSurfaceFormatKHR surfaceFormat = pick_surface_format(swapchainSupport.formats);
    VkPresentModeKHR presentMode = pick_present_mode(swapchainSupport.presentModes);
    VkExtent2D extent = pick_swap_extent(&swapchainSupport.capabilities, window);

    uint32_t imageCount = swapchainSupport.capabilities.minImageCount + 1;
    if (swapchainSupport.capabilities.maxImageCount > 0 && imageCount > swapchainSupport.capabilities.maxImageCount) {
        imageCount = swapchainSupport.capabilities.maxImageCount;
    }

    VkSwapchainCreateInfoKHR createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    createInfo.surface = surface;
    createInfo.minImageCount = imageCount;
    createInfo.imageFormat = surfaceFormat.format;
    createInfo.imageColorSpace = surfaceFormat.colorSpace;
    createInfo.imageExtent = extent;
    createInfo.imageArrayLayers = 1;
    createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

    QueueFamilyIndices indices = find_queue_families(device.physical, surface);
    uint32_t queueFamilyIndices[] = {indices.graphicsFamily, indices.presentFamily};

    if (indices.graphicsFamily != indices.presentFamily) {
        createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
        createInfo.queueFamilyIndexCount = 2;
        createInfo.pQueueFamilyIndices = queueFamilyIndices;
    } else {
        createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    }

    createInfo.preTransform = swapchainSupport.capabilities.currentTransform;
    createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    createInfo.presentMode = presentMode;
    createInfo.clipped = VK_TRUE;
    createInfo.oldSwapchain = VK_NULL_HANDLE;

    if (vkCreateSwapchainKHR(device.logical, &createInfo, NULL, &swapchain->data) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to create vulkan swap chain");
    }

    vkGetSwapchainImagesKHR(device.logical, swapchain->data, &imageCount, NULL);
    swapchain->images = NULL;
    arraddn(swapchain->images, imageCount);
    vkGetSwapchainImagesKHR(device.logical, swapchain->data, &imageCount, swapchain->images);
    swapchain->imageFormat = surfaceFormat.format;
    swapchain->extent = extent;

    create_image_views(swapchain, device);
}

void create_image_views(
    CvveSwapchain* swapchain,
    CvveDevice device
) {
    swapchain->imageViews = NULL;
    arraddn(swapchain->imageViews, arrlen(swapchain->images));

    for (uint32_t i = 0; i < arrlen(swapchain->images); i++) {
        VkImageViewCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        createInfo.image = swapchain->images[i];
        createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        createInfo.format = swapchain->imageFormat;
        createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        createInfo.subresourceRange.baseMipLevel = 0;
        createInfo.subresourceRange.levelCount = 1;
        createInfo.subresourceRange.baseArrayLayer = 0;
        createInfo.subresourceRange.layerCount = 1;
        if (vkCreateImageView(device.logical, &createInfo, NULL, &swapchain->imageViews[i]) != VK_SUCCESS) {
            throw_verr(VERR_LEVEL_ERROR, "Failed to create a vulkan image view");
        }
    }
}

void destroy_swapchain(
    CvveSwapchain swapchain,
    CvveDevice device
) {
    for(int i = 0; i < arrlen(swapchain.imageViews); i++) {
        vkDestroyImageView(device.logical, swapchain.imageViews[i], NULL);
    }
    vkDestroySwapchainKHR(device.logical, swapchain.data, NULL);
}