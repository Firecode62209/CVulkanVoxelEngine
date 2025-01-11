#ifndef APP_H
#define APP_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "v_err.h"
#include <stdlib.h>
#include <stdbool.h>
#include "cvve/element.h"

extern const uint32_t WINDOW_WIDTH;
extern const uint32_t WINDOW_HEIGHT;

typedef struct VkApp VkApp; 

VkApp* create_app();
void init_app(VkApp* app);
void init_window(VkApp* app);
void run_app(VkApp* app);
void destroy_app(VkApp* app);
static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

#endif
