# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aaybar/Documents/AsciiAdventure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aaybar/Documents/AsciiAdventure/build

# Include any dependencies generated for this target.
include CMakeFiles/AsciiAdventure.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AsciiAdventure.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AsciiAdventure.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AsciiAdventure.dir/flags.make

CMakeFiles/AsciiAdventure.dir/src/main.o: CMakeFiles/AsciiAdventure.dir/flags.make
CMakeFiles/AsciiAdventure.dir/src/main.o: ../src/main.cpp
CMakeFiles/AsciiAdventure.dir/src/main.o: CMakeFiles/AsciiAdventure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aaybar/Documents/AsciiAdventure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AsciiAdventure.dir/src/main.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AsciiAdventure.dir/src/main.o -MF CMakeFiles/AsciiAdventure.dir/src/main.o.d -o CMakeFiles/AsciiAdventure.dir/src/main.o -c /home/aaybar/Documents/AsciiAdventure/src/main.cpp

CMakeFiles/AsciiAdventure.dir/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AsciiAdventure.dir/src/main.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aaybar/Documents/AsciiAdventure/src/main.cpp > CMakeFiles/AsciiAdventure.dir/src/main.i

CMakeFiles/AsciiAdventure.dir/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AsciiAdventure.dir/src/main.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aaybar/Documents/AsciiAdventure/src/main.cpp -o CMakeFiles/AsciiAdventure.dir/src/main.s

# Object files for target AsciiAdventure
AsciiAdventure_OBJECTS = \
"CMakeFiles/AsciiAdventure.dir/src/main.o"

# External object files for target AsciiAdventure
AsciiAdventure_EXTERNAL_OBJECTS =

AsciiAdventure: CMakeFiles/AsciiAdventure.dir/src/main.o
AsciiAdventure: CMakeFiles/AsciiAdventure.dir/build.make
AsciiAdventure: CMakeFiles/AsciiAdventure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aaybar/Documents/AsciiAdventure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AsciiAdventure"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AsciiAdventure.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AsciiAdventure.dir/build: AsciiAdventure
.PHONY : CMakeFiles/AsciiAdventure.dir/build

CMakeFiles/AsciiAdventure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AsciiAdventure.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AsciiAdventure.dir/clean

CMakeFiles/AsciiAdventure.dir/depend:
	cd /home/aaybar/Documents/AsciiAdventure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aaybar/Documents/AsciiAdventure /home/aaybar/Documents/AsciiAdventure /home/aaybar/Documents/AsciiAdventure/build /home/aaybar/Documents/AsciiAdventure/build /home/aaybar/Documents/AsciiAdventure/build/CMakeFiles/AsciiAdventure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AsciiAdventure.dir/depend

