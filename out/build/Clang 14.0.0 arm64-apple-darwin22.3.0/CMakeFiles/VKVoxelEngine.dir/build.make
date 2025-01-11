# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/landondevendorf/Programs/CVulkanVoxelEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0"

# Include any dependencies generated for this target.
include CMakeFiles/VKVoxelEngine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/VKVoxelEngine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/VKVoxelEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VKVoxelEngine.dir/flags.make

CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/buffer.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/buffer.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/buffer.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/buffer.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/command.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/command.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/command.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/command.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/device.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/device.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/device.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/device.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/draw.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/draw.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/draw.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/draw.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/element.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/element.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/element.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/element.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/frame_buffers.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/frame_buffers.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/frame_buffers.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/frame_buffers.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/graphics_pipeline.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/graphics_pipeline.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/graphics_pipeline.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/graphics_pipeline.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/instance.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/instance.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/instance.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/instance.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/queue.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/queue.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/queue.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/queue.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/shader.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/shader.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/shader.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/shader.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/surface.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/surface.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/surface.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/surface.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/swapchain.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/swapchain.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/swapchain.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/swapchain.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/validation_layers.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/validation_layers.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/validation_layers.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/validation_layers.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.s

CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/vertex.c
CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/vertex.c

CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/vertex.c > CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.i

CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/cvve/vertex.c -o CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.s

CMakeFiles/VKVoxelEngine.dir/src/app.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/app.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/app.c
CMakeFiles/VKVoxelEngine.dir/src/app.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/VKVoxelEngine.dir/src/app.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/app.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/app.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/app.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/app.c

CMakeFiles/VKVoxelEngine.dir/src/app.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/app.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/app.c > CMakeFiles/VKVoxelEngine.dir/src/app.c.i

CMakeFiles/VKVoxelEngine.dir/src/app.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/app.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/app.c -o CMakeFiles/VKVoxelEngine.dir/src/app.c.s

CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/file_reader.c
CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/file_reader.c

CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/file_reader.c > CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.i

CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/file_reader.c -o CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.s

CMakeFiles/VKVoxelEngine.dir/src/main.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/main.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/main.c
CMakeFiles/VKVoxelEngine.dir/src/main.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/VKVoxelEngine.dir/src/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/main.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/main.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/main.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/main.c

CMakeFiles/VKVoxelEngine.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/main.c > CMakeFiles/VKVoxelEngine.dir/src/main.c.i

CMakeFiles/VKVoxelEngine.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/main.c -o CMakeFiles/VKVoxelEngine.dir/src/main.c.s

CMakeFiles/VKVoxelEngine.dir/src/v_err.c.o: CMakeFiles/VKVoxelEngine.dir/flags.make
CMakeFiles/VKVoxelEngine.dir/src/v_err.c.o: /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/v_err.c
CMakeFiles/VKVoxelEngine.dir/src/v_err.c.o: CMakeFiles/VKVoxelEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/VKVoxelEngine.dir/src/v_err.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/VKVoxelEngine.dir/src/v_err.c.o -MF CMakeFiles/VKVoxelEngine.dir/src/v_err.c.o.d -o CMakeFiles/VKVoxelEngine.dir/src/v_err.c.o -c /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/v_err.c

CMakeFiles/VKVoxelEngine.dir/src/v_err.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VKVoxelEngine.dir/src/v_err.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/v_err.c > CMakeFiles/VKVoxelEngine.dir/src/v_err.c.i

CMakeFiles/VKVoxelEngine.dir/src/v_err.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VKVoxelEngine.dir/src/v_err.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/landondevendorf/Programs/CVulkanVoxelEngine/src/v_err.c -o CMakeFiles/VKVoxelEngine.dir/src/v_err.c.s

# Object files for target VKVoxelEngine
VKVoxelEngine_OBJECTS = \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/app.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/main.c.o" \
"CMakeFiles/VKVoxelEngine.dir/src/v_err.c.o"

# External object files for target VKVoxelEngine
VKVoxelEngine_EXTERNAL_OBJECTS =

VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/buffer.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/command.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/device.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/draw.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/element.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/frame_buffers.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/graphics_pipeline.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/instance.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/queue.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/shader.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/surface.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/swapchain.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/validation_layers.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/cvve/vertex.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/app.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/file_reader.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/main.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/src/v_err.c.o
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/build.make
VKVoxelEngine: /opt/homebrew/lib/libglfw.3.4.dylib
VKVoxelEngine: /usr/local/lib/libvulkan.dylib
VKVoxelEngine: /opt/homebrew/lib/libglslang.15.1.0.dylib
VKVoxelEngine: /opt/homebrew/lib/libglslang-default-resource-limits.15.1.0.dylib
VKVoxelEngine: CMakeFiles/VKVoxelEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_19) "Linking C executable VKVoxelEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VKVoxelEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VKVoxelEngine.dir/build: VKVoxelEngine
.PHONY : CMakeFiles/VKVoxelEngine.dir/build

CMakeFiles/VKVoxelEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VKVoxelEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VKVoxelEngine.dir/clean

CMakeFiles/VKVoxelEngine.dir/depend:
	cd "/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/landondevendorf/Programs/CVulkanVoxelEngine /Users/landondevendorf/Programs/CVulkanVoxelEngine "/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0" "/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0" "/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles/VKVoxelEngine.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/VKVoxelEngine.dir/depend
