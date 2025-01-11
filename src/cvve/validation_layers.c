#include "cvve/validation_layers.h"

const char* VALIDATION_LAYERS[1] = {
    "VK_LAYER_KHRONOS_validation"
};
uint32_t VALIDATION_LAYER_COUNT = 1;

#ifdef NDEBUG
    bool ENABLE_VALIDATION_LAYERS = false;
#else
    bool ENABLE_VALIDATION_LAYERS = true;
#endif

bool check_validation_layer_support() {
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, NULL);

    VkLayerProperties* availableLayers = malloc(layerCount * sizeof(VkLayerProperties));
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers);

    for(uint32_t i = 0; i < VALIDATION_LAYER_COUNT; i++) {
        bool layerFound = false;
        for (uint32_t j = 0; j < layerCount; j++) {
            if(strcmp(VALIDATION_LAYERS[i], availableLayers[j].layerName) == 0) {
                layerFound = true;
                break;
            }
        }

        if (!layerFound) {
            free(availableLayers);
            availableLayers = NULL;
            return false;
        }
    }

    free(availableLayers);
    availableLayers = NULL;
    return true;
}