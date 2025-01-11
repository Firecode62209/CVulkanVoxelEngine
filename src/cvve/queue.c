#include "cvve/queue.h"

QueueFamilyIndices find_queue_families(
    VkPhysicalDevice physicalDevice, 
    VkSurfaceKHR surface
) {
    QueueFamilyIndices indices;
    indices.hasGraphicsValue = false;
    indices.hasPresentValue = false;

    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, NULL);
    VkQueueFamilyProperties* queueFamilies = malloc(sizeof(VkQueueFamilyProperties) * queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, queueFamilies);

    for(uint32_t i = 0; i < queueFamilyCount; i++) {
        if (queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.graphicsFamily = (uint32_t)i;
            indices.hasGraphicsValue = true;
        }

        VkBool32 presentSupport = false;
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, i, surface, &presentSupport);

        if (presentSupport) {
            indices.presentFamily = (uint32_t)i;
            indices.hasPresentValue = true;
        }

        if (queue_has_support(&indices)) break;
    }

    return indices;
}

bool queue_has_support(
    QueueFamilyIndices* indices
) {
    return indices->hasGraphicsValue && indices->hasPresentValue;
}