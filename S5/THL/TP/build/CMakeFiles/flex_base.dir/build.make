# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/baptiste/Documents/université/S5/THL/TP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/baptiste/Documents/université/S5/THL/TP/build

# Include any dependencies generated for this target.
include CMakeFiles/flex_base.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/flex_base.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/flex_base.dir/flags.make

scanner.cpp: ../scanner.ll
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/baptiste/Documents/université/S5/THL/TP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[FLEX][scanner] Building scanner with flex 2.6.0"
	cd /home/baptiste/Documents/université/S5/THL/TP && /usr/bin/flex -o/home/baptiste/Documents/université/S5/THL/TP/build/scanner.cpp scanner.ll

CMakeFiles/flex_base.dir/scanner.cpp.o: CMakeFiles/flex_base.dir/flags.make
CMakeFiles/flex_base.dir/scanner.cpp.o: scanner.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/baptiste/Documents/université/S5/THL/TP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/flex_base.dir/scanner.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flex_base.dir/scanner.cpp.o -c /home/baptiste/Documents/université/S5/THL/TP/build/scanner.cpp

CMakeFiles/flex_base.dir/scanner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flex_base.dir/scanner.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/baptiste/Documents/université/S5/THL/TP/build/scanner.cpp > CMakeFiles/flex_base.dir/scanner.cpp.i

CMakeFiles/flex_base.dir/scanner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flex_base.dir/scanner.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/baptiste/Documents/université/S5/THL/TP/build/scanner.cpp -o CMakeFiles/flex_base.dir/scanner.cpp.s

CMakeFiles/flex_base.dir/scanner.cpp.o.requires:

.PHONY : CMakeFiles/flex_base.dir/scanner.cpp.o.requires

CMakeFiles/flex_base.dir/scanner.cpp.o.provides: CMakeFiles/flex_base.dir/scanner.cpp.o.requires
	$(MAKE) -f CMakeFiles/flex_base.dir/build.make CMakeFiles/flex_base.dir/scanner.cpp.o.provides.build
.PHONY : CMakeFiles/flex_base.dir/scanner.cpp.o.provides

CMakeFiles/flex_base.dir/scanner.cpp.o.provides.build: CMakeFiles/flex_base.dir/scanner.cpp.o


# Object files for target flex_base
flex_base_OBJECTS = \
"CMakeFiles/flex_base.dir/scanner.cpp.o"

# External object files for target flex_base
flex_base_EXTERNAL_OBJECTS =

flex_base: CMakeFiles/flex_base.dir/scanner.cpp.o
flex_base: CMakeFiles/flex_base.dir/build.make
flex_base: CMakeFiles/flex_base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/baptiste/Documents/université/S5/THL/TP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable flex_base"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flex_base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/flex_base.dir/build: flex_base

.PHONY : CMakeFiles/flex_base.dir/build

CMakeFiles/flex_base.dir/requires: CMakeFiles/flex_base.dir/scanner.cpp.o.requires

.PHONY : CMakeFiles/flex_base.dir/requires

CMakeFiles/flex_base.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flex_base.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flex_base.dir/clean

CMakeFiles/flex_base.dir/depend: scanner.cpp
	cd /home/baptiste/Documents/université/S5/THL/TP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/baptiste/Documents/université/S5/THL/TP /home/baptiste/Documents/université/S5/THL/TP /home/baptiste/Documents/université/S5/THL/TP/build /home/baptiste/Documents/université/S5/THL/TP/build /home/baptiste/Documents/université/S5/THL/TP/build/CMakeFiles/flex_base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/flex_base.dir/depend

