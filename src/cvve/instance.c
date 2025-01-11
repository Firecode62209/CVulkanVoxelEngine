#include "cvve/instance.h"

void create_instance(VkInstance* instance) {
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    const char** requiredExtensions = NULL;
    for (int i = 0; i < glfwExtensionCount; i++) {
        arrpush(requiredExtensions, glfwExtensions[i]);
    }
    arrpush(requiredExtensions, VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
    arrpush(requiredExtensions, VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME); 

    createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
    
    createInfo.enabledExtensionCount = arrlen(requiredExtensions);
    createInfo.ppEnabledExtensionNames = requiredExtensions;

    if (ENABLE_VALIDATION_LAYERS && !check_validation_layer_support()) {
        throw_verr(VERR_LEVEL_ERROR, "Validation layers requested, not supported");
    }

    if (ENABLE_VALIDATION_LAYERS) {
        createInfo.enabledLayerCount = VALIDATION_LAYER_COUNT;
        createInfo.ppEnabledLayerNames = VALIDATION_LAYERS;
    } else {
        createInfo.enabledLayerCount = 0;
    }

    if (vkCreateInstance(&createInfo, NULL, instance) != VK_SUCCESS) {
         throw_verr(VERR_LEVEL_ERROR, "Failed to create Vulkan Instance");
    };
}

void destroy_instance(VkInstance instance) {
    vkDestroyInstance(instance, NULL);
}