#ifndef CVVE_DEVICE_H
#define CVVE_DEVICE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdbool.h>
#include "v_err.h"
#include "queue.h"
#include "stb_ds.h"
#include "validation_layers.h"
#include "swapchain_support.h"

extern const char* DEVICE_EXTENSIONS[2];
extern uint32_t DEVICE_EXTENSION_COUNT;


typedef struct CvveDevice {
    VkPhysicalDevice physical;
    VkDevice logical;
    CvveQueues queues;
} CvveDevice;

void create_devices(
    CvveDevice* device,
    VkInstance instance,
    VkSurfaceKHR surface
);
void pick_physical_device(
    CvveDevice* device,
    VkInstance instance, 
    VkSurfaceKHR surface
);
bool check_device_suitability(
    VkPhysicalDevice device, 
    VkSurfaceKHR surface
);
bool check_device_extension_support(
    VkPhysicalDevice device
);
void create_logical_device(
    CvveDevice* device,
    VkSurfaceKHR surface 
);
void destroy_devices(
    CvveDevice device
);
#endif