cmake_minimum_required(VERSION 3.5.0)
project(VKVoxelEngine VERSION 0.1.0 LANGUAGES C)


FILE(GLOB VKV_SRC src/*.c)
FILE(GLOB VKV_CVVE src/cvve/*.c)
ADD_EXECUTABLE(VKVoxelEngine 
    ${VKV_CVVE}
    ${VKV_SRC} 
)

set(HOMEBREW_)

find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glslang REQUIRED)
include(CTest)
enable_testing()

target_include_directories(VKVoxelEngine
    PUBLIC
    ${Vulkan_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/lib
)
target_link_libraries(VKVoxelEngine 
    glfw
    ${Vulkan_LIBRARIES}
    glslang::glslang
    glslang::glslang-default-resource-limits
    cglm_headers
)
add_subdirectory(lib/cglm/ EXCLUDE_FROM_ALL)
