#ifndef CVVE_VALIDATION_LAYERS_H
#define CVVE_VALIDATION_LAYERS_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdbool.h>
#include "stb_ds.h"
#include <stdlib.h>
#include <stdio.h>

extern const char* VALIDATION_LAYERS[1];
extern uint32_t VALIDATION_LAYER_COUNT;
extern bool ENABLE_VALIDATION_LAYERS;

bool check_validation_layer_support();

#endif