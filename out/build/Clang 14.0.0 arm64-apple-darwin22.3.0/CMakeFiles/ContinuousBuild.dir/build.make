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

# Utility rule file for ContinuousBuild.

# Include any custom commands dependencies for this target.
include CMakeFiles/ContinuousBuild.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ContinuousBuild.dir/progress.make

CMakeFiles/ContinuousBuild:
	/opt/homebrew/Cellar/cmake/3.25.3/bin/ctest -D ContinuousBuild

ContinuousBuild: CMakeFiles/ContinuousBuild
ContinuousBuild: CMakeFiles/ContinuousBuild.dir/build.make
.PHONY : ContinuousBuild

# Rule to build all files generated by this target.
CMakeFiles/ContinuousBuild.dir/build: ContinuousBuild
.PHONY : CMakeFiles/ContinuousBuild.dir/build

CMakeFiles/ContinuousBuild.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ContinuousBuild.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ContinuousBuild.dir/clean

CMakeFiles/ContinuousBuild.dir/depend:
	cd "/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/landondevendorf/Programs/CVulkanVoxelEngine /Users/landondevendorf/Programs/CVulkanVoxelEngine "/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0" "/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0" "/Users/landondevendorf/Programs/CVulkanVoxelEngine/out/build/Clang 14.0.0 arm64-apple-darwin22.3.0/CMakeFiles/ContinuousBuild.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ContinuousBuild.dir/depend
