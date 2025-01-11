#ifndef CVVE_INSTANCE_H
#define CVVE_INSTANCE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "v_err.h"
#include "stb_ds.h"
#include "validation_layers.h"

void create_instance(VkInstance* instance);
void destroy_instance(VkInstance instance);

#endif