# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yli25/projects/11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yli25/projects/11/build

# Include any dependencies generated for this target.
include CMakeFiles/11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/11.dir/flags.make

CMakeFiles/11.dir/main.o: CMakeFiles/11.dir/flags.make
CMakeFiles/11.dir/main.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yli25/projects/11/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/11.dir/main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/11.dir/main.o -c /home/yli25/projects/11/main.cpp

CMakeFiles/11.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/11.dir/main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yli25/projects/11/main.cpp > CMakeFiles/11.dir/main.i

CMakeFiles/11.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/11.dir/main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yli25/projects/11/main.cpp -o CMakeFiles/11.dir/main.s

CMakeFiles/11.dir/main.o.requires:
.PHONY : CMakeFiles/11.dir/main.o.requires

CMakeFiles/11.dir/main.o.provides: CMakeFiles/11.dir/main.o.requires
	$(MAKE) -f CMakeFiles/11.dir/build.make CMakeFiles/11.dir/main.o.provides.build
.PHONY : CMakeFiles/11.dir/main.o.provides

CMakeFiles/11.dir/main.o.provides.build: CMakeFiles/11.dir/main.o

# Object files for target 11
11_OBJECTS = \
"CMakeFiles/11.dir/main.o"

# External object files for target 11
11_EXTERNAL_OBJECTS =

11: CMakeFiles/11.dir/main.o
11: CMakeFiles/11.dir/build.make
11: CMakeFiles/11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable 11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/11.dir/build: 11
.PHONY : CMakeFiles/11.dir/build

CMakeFiles/11.dir/requires: CMakeFiles/11.dir/main.o.requires
.PHONY : CMakeFiles/11.dir/requires

CMakeFiles/11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/11.dir/clean

CMakeFiles/11.dir/depend:
	cd /home/yli25/projects/11/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yli25/projects/11 /home/yli25/projects/11 /home/yli25/projects/11/build /home/yli25/projects/11/build /home/yli25/projects/11/build/CMakeFiles/11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/11.dir/depend
