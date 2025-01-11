#include "cvve/device.h"

const char* DEVICE_EXTENSIONS[2] = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME,
    "VK_KHR_portability_subset"
};
uint32_t DEVICE_EXTENSION_COUNT = 2;

void create_devices(
    CvveDevice* device,
    VkInstance instance,
    VkSurfaceKHR surface
) {
    pick_physical_device(
        device,
        instance,
        surface
    );
    create_logical_device(
        device,
        surface
    );
}
void pick_physical_device(
    CvveDevice* device,
    VkInstance instance, 
    VkSurfaceKHR surface
) {
    device->physical = VK_NULL_HANDLE;

    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, NULL);

    if (deviceCount == 0) {
        throw_verr(VERR_LEVEL_ERROR, "GPU device(s) requested, 0 found");
    }

    VkPhysicalDevice* devices = malloc(sizeof(VkPhysicalDevice) * deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount, devices);
    for (uint32_t i = 0; i < deviceCount; i++) {
        if(check_device_suitability(devices[i], surface)) {
            device->physical = devices[i];
            break;
        }
    }
    if (device->physical == VK_NULL_HANDLE) {
        throw_verr(VERR_LEVEL_ERROR, "GPU device(s) request, 0 suitable devices found");
    }

    free(devices);
}
bool check_device_suitability(
    VkPhysicalDevice device,
    VkSurfaceKHR surface
) {
    QueueFamilyIndices indices = find_queue_families(device, surface);

    bool extensionsSupported = check_device_extension_support(device);
    bool swapchainSuitable = true;
    if (extensionsSupported) {
        SwapchainSupportDetails swapchainDetails = query_swapchain_support(device, surface);
        swapchainSuitable = arrlen(swapchainDetails.formats) != 0 && arrlen(swapchainDetails.presentModes) != 0;
    }
    return queue_has_support(&indices) && extensionsSupported && swapchainSuitable;
}
bool check_device_extension_support(
    VkPhysicalDevice device
) {
    uint32_t extensionCount;
    vkEnumerateDeviceExtensionProperties(device, NULL, &extensionCount, NULL);

    VkExtensionProperties* availableExtensions = malloc(sizeof(VkExtensionProperties) * extensionCount);
    vkEnumerateDeviceExtensionProperties(device, NULL, &extensionCount, availableExtensions);
    
    struct {const char* key; int value;}* requiredExtensions;
    for(int i = 0; i < arrlen(DEVICE_EXTENSIONS); i++) {
        shput(requiredExtensions, DEVICE_EXTENSIONS[i], 1);
    }

    for(int i = 0; i < extensionCount; i++) {
            shdel(requiredExtensions, (const char*) availableExtensions[i].extensionName);
    }

    bool extensionsSupported = shlen(requiredExtensions) == 0;
    free(availableExtensions);
    shfree(requiredExtensions);
    return extensionsSupported;
}
void create_logical_device(
    CvveDevice* device,
    VkSurfaceKHR surface
) {
    QueueFamilyIndices indices = find_queue_families(device->physical, surface);
    
    VkDeviceQueueCreateInfo* queueCreateInfos = NULL;
    struct {u_int32_t key; int value;}* uniqueQueueFamilies = NULL;
    hmput(uniqueQueueFamilies, indices.graphicsFamily, 1);
    hmput(uniqueQueueFamilies, indices.presentFamily, 1);   
    
    float queuePriority = 1.0f;
    for (uint32_t i = 0; i < hmlen(uniqueQueueFamilies); i++) {
        VkDeviceQueueCreateInfo queueCreateInfo = {};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = uniqueQueueFamilies[i].key;
        queueCreateInfo.queueCount = 1;
        queueCreateInfo.pQueuePriorities = &queuePriority;
        arrpush(queueCreateInfos, queueCreateInfo);
    }

    VkPhysicalDeviceFeatures deviceFeatures = {};

    VkDeviceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    createInfo.pQueueCreateInfos = queueCreateInfos;
    createInfo.queueCreateInfoCount = arrlen(queueCreateInfos);

    createInfo.pEnabledFeatures = &deviceFeatures;
    createInfo.enabledExtensionCount = DEVICE_EXTENSION_COUNT;
    createInfo.ppEnabledExtensionNames =  DEVICE_EXTENSIONS;

    if (ENABLE_VALIDATION_LAYERS) {
        createInfo.enabledLayerCount = VALIDATION_LAYER_COUNT;
        createInfo.ppEnabledLayerNames = VALIDATION_LAYERS;
    } else {
        createInfo.enabledLayerCount = 0;
    }

    if (vkCreateDevice(device->physical, &createInfo, NULL, &device->logical) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to create vulkan logical device");
    }
    vkGetDeviceQueue(device->logical, indices.graphicsFamily, 0, &device->queues.graphics);
    vkGetDeviceQueue(device->logical, indices.presentFamily, 0, &device->queues.present);
}
void destroy_devices(
    CvveDevice device
) {
    vkDestroyDevice(device.logical, NULL);
}