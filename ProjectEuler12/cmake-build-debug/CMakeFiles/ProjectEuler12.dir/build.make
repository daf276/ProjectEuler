# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/attila/c++_projects/ProjectEuler12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/attila/c++_projects/ProjectEuler12/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjectEuler12.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjectEuler12.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjectEuler12.dir/flags.make

CMakeFiles/ProjectEuler12.dir/main.cpp.o: CMakeFiles/ProjectEuler12.dir/flags.make
CMakeFiles/ProjectEuler12.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/attila/c++_projects/ProjectEuler12/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProjectEuler12.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectEuler12.dir/main.cpp.o -c /home/attila/c++_projects/ProjectEuler12/main.cpp

CMakeFiles/ProjectEuler12.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectEuler12.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/attila/c++_projects/ProjectEuler12/main.cpp > CMakeFiles/ProjectEuler12.dir/main.cpp.i

CMakeFiles/ProjectEuler12.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectEuler12.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/attila/c++_projects/ProjectEuler12/main.cpp -o CMakeFiles/ProjectEuler12.dir/main.cpp.s

CMakeFiles/ProjectEuler12.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ProjectEuler12.dir/main.cpp.o.requires

CMakeFiles/ProjectEuler12.dir/main.cpp.o.provides: CMakeFiles/ProjectEuler12.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProjectEuler12.dir/build.make CMakeFiles/ProjectEuler12.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ProjectEuler12.dir/main.cpp.o.provides

CMakeFiles/ProjectEuler12.dir/main.cpp.o.provides.build: CMakeFiles/ProjectEuler12.dir/main.cpp.o


# Object files for target ProjectEuler12
ProjectEuler12_OBJECTS = \
"CMakeFiles/ProjectEuler12.dir/main.cpp.o"

# External object files for target ProjectEuler12
ProjectEuler12_EXTERNAL_OBJECTS =

ProjectEuler12: CMakeFiles/ProjectEuler12.dir/main.cpp.o
ProjectEuler12: CMakeFiles/ProjectEuler12.dir/build.make
ProjectEuler12: CMakeFiles/ProjectEuler12.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/attila/c++_projects/ProjectEuler12/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ProjectEuler12"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProjectEuler12.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjectEuler12.dir/build: ProjectEuler12

.PHONY : CMakeFiles/ProjectEuler12.dir/build

CMakeFiles/ProjectEuler12.dir/requires: CMakeFiles/ProjectEuler12.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ProjectEuler12.dir/requires

CMakeFiles/ProjectEuler12.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProjectEuler12.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProjectEuler12.dir/clean

CMakeFiles/ProjectEuler12.dir/depend:
	cd /home/attila/c++_projects/ProjectEuler12/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/attila/c++_projects/ProjectEuler12 /home/attila/c++_projects/ProjectEuler12 /home/attila/c++_projects/ProjectEuler12/cmake-build-debug /home/attila/c++_projects/ProjectEuler12/cmake-build-debug /home/attila/c++_projects/ProjectEuler12/cmake-build-debug/CMakeFiles/ProjectEuler12.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjectEuler12.dir/depend

