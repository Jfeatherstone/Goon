# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jack/cpp-workspace/Goon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jack/cpp-workspace/Goon/build

# Include any dependencies generated for this target.
include CMakeFiles/Goon.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Goon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Goon.dir/flags.make

CMakeFiles/Goon.dir/src/main.cpp.o: CMakeFiles/Goon.dir/flags.make
CMakeFiles/Goon.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jack/cpp-workspace/Goon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Goon.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Goon.dir/src/main.cpp.o -c /home/jack/cpp-workspace/Goon/src/main.cpp

CMakeFiles/Goon.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Goon.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jack/cpp-workspace/Goon/src/main.cpp > CMakeFiles/Goon.dir/src/main.cpp.i

CMakeFiles/Goon.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Goon.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jack/cpp-workspace/Goon/src/main.cpp -o CMakeFiles/Goon.dir/src/main.cpp.s

# Object files for target Goon
Goon_OBJECTS = \
"CMakeFiles/Goon.dir/src/main.cpp.o"

# External object files for target Goon
Goon_EXTERNAL_OBJECTS =

Goon: CMakeFiles/Goon.dir/src/main.cpp.o
Goon: CMakeFiles/Goon.dir/build.make
Goon: /usr/lib/libsfml-graphics.so.2.5.1
Goon: /usr/lib/libsfml-audio.so.2.5.1
Goon: /usr/lib/libsfml-window.so.2.5.1
Goon: /usr/lib/libsfml-system.so.2.5.1
Goon: CMakeFiles/Goon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jack/cpp-workspace/Goon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Goon"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Goon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Goon.dir/build: Goon

.PHONY : CMakeFiles/Goon.dir/build

CMakeFiles/Goon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Goon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Goon.dir/clean

CMakeFiles/Goon.dir/depend:
	cd /home/jack/cpp-workspace/Goon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jack/cpp-workspace/Goon /home/jack/cpp-workspace/Goon /home/jack/cpp-workspace/Goon/build /home/jack/cpp-workspace/Goon/build /home/jack/cpp-workspace/Goon/build/CMakeFiles/Goon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Goon.dir/depend

