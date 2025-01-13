#include "cvve/uniform.h"

void create_descriptor_set_layout(
    CvveDescriptor* descriptor,
    CvveDevice device
) {
    VkDescriptorSetLayoutBinding uboLayoutBinding = {};
    uboLayoutBinding.binding = 0;
    uboLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    uboLayoutBinding.descriptorCount = 1;
    uboLayoutBinding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
    uboLayoutBinding.pImmutableSamplers = NULL;

    VkDescriptorSetLayoutCreateInfo layoutInfo = {};
    layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    layoutInfo.bindingCount = 1;
    layoutInfo.pBindings = &uboLayoutBinding;

    if (vkCreateDescriptorSetLayout(device.logical, &layoutInfo, NULL, &descriptor->setLayout) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to create descriptor set layout!");
    }
}

void create_uniform_buffers(
    CvveBuffer** uniformBuffers,
    void*** uniformBuffersMapped,
    CvveDevice device
) {
    VkDeviceSize bufferSize = sizeof(UniformBufferObject);

    *uniformBuffers = NULL;
    arraddn(*uniformBuffers, MAX_FRAMES_IN_FLIGHT);
    *uniformBuffersMapped = NULL;
    arraddn(*uniformBuffersMapped, MAX_FRAMES_IN_FLIGHT);

    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        create_buffer(&(*uniformBuffers)[i], bufferSize, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, device);
    
        vkMapMemory(device.logical, (*uniformBuffers)[i].memory, 0, bufferSize, 0, &(*uniformBuffersMapped)[i]);
    }    
}
void update_uniform_buffer(
    void** uniformBuffersMapped,
    uint32_t currentImage,
    VkExtent2D extent
) {
    double time = glfwGetTime();

    UniformBufferObject ubo = {};
    glm_mat4_identity(ubo.model);
    glm_rotate(ubo.model, time * glm_rad(90.0f), (vec3){0.5f, 0.5f, 1.0f});
    glm_lookat((vec3){2.0f, 2.0f, 2.0f}, GLM_VEC3_ZERO, (vec3){0.0f, 0.0f, 1.0f}, ubo.view);
    glm_perspective(glm_rad(45.0f), extent.width / (float) extent.height, 0.1f, 10.0f, ubo.proj);
    ubo.proj[1][1] *= -1;

    memcpy(uniformBuffersMapped[currentImage], &ubo, sizeof(ubo));
}
void destroy_uniform_buffers(
    CvveBuffer* uniformBuffers,
    CvveDevice device
) {
    for(size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        destroy_buffer(uniformBuffers[i], device);
    }
}
void create_descriptor_pool(
    CvveDescriptor* descriptor,
    CvveDevice device
) {
    VkDescriptorPoolSize poolSize = {};
    poolSize.type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    poolSize.descriptorCount = (uint32_t)MAX_FRAMES_IN_FLIGHT;

    VkDescriptorPoolCreateInfo poolInfo = {};
    poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    poolInfo.poolSizeCount = 1;
    poolInfo.pPoolSizes = &poolSize;
    poolInfo.maxSets = (uint32_t)MAX_FRAMES_IN_FLIGHT;

    if (vkCreateDescriptorPool(device.logical, &poolInfo, NULL, &descriptor->pool) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to create descriptor pool");
    }
}

void create_descriptor_sets(
    CvveDescriptor* descriptor,
    CvveDevice device
) {
    VkDescriptorSetLayout* layouts = NULL;
    for(size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        arrpush(layouts, descriptor->setLayout);
    }
    VkDescriptorSetAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    allocInfo.descriptorPool = descriptor->pool;
    allocInfo.descriptorSetCount = (uint32_t) MAX_FRAMES_IN_FLIGHT;
    allocInfo.pSetLayouts = layouts;

    descriptor->sets = NULL;
    arraddn(descriptor->sets, MAX_FRAMES_IN_FLIGHT);
    if (vkAllocateDescriptorSets(device.logical, &allocInfo, descriptor->sets) != VK_SUCCESS) {
        throw_verr(VERR_LEVEL_ERROR, "Failed to allocate descriptor sets");
    }
}
void destroy_descriptor(
    CvveDescriptor descriptor,
    CvveDevice device
) {
    vkDestroyDescriptorPool(device.logical, descriptor.pool, NULL);
    vkDestroyDescriptorSetLayout(device.logical, descriptor.setLayout, NULL);
}
void create_descriptor(
    CvveDescriptor* descriptor,
    CvveBuffer* uniformBuffers,
    CvveDevice device
) {
    create_descriptor_set_layout(descriptor, device);
    create_descriptor_pool(descriptor, device);
    create_descriptor_sets(descriptor, device);

    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        VkDescriptorBufferInfo bufferInfo = {};
        bufferInfo.buffer = uniformBuffers[i].data;
        bufferInfo.offset = 0;
        bufferInfo.range = sizeof(UniformBufferObject);

        VkWriteDescriptorSet descriptorWrite = {};
        descriptorWrite.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrite.dstSet = descriptor->sets[i];
        descriptorWrite.dstBinding = 0;
        descriptorWrite.dstArrayElement = 0;
        descriptorWrite.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorWrite.descriptorCount = 1;
        descriptorWrite.pBufferInfo = &bufferInfo;

        vkUpdateDescriptorSets(device.logical, 1, &descriptorWrite, 0, NULL);
    }
}
