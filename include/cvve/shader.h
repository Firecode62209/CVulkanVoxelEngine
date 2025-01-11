#ifndef CVVE_SHADER_H
#define CVVE_SHADER_H

#include <glslang/Include/glslang_c_interface.h>
#include <glslang/Public/resource_limits_c.h>
#include <stdio.h>
#include "v_err.h"

typedef struct SpirVBinary {
    uint32_t* words;
    int size;
} SpirVBinary;

SpirVBinary compile_shader_to_spirv(
    glslang_stage_t stage,
    const char* shaderSource,
    const char* fileName
);

#endif