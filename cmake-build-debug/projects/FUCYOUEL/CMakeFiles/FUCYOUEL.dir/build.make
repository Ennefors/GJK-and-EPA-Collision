# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/bill/Desktop/clion-2017.2.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/bill/Desktop/clion-2017.2.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug"

# Include any dependencies generated for this target.
include projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/depend.make

# Include the progress variables for this target.
include projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/progress.make

# Include the compile flags for this target's objects.
include projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/flags.make

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o: projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/flags.make
projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o: ../projects/FUCYOUEL/code/exampleapp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/FUCYOUEL" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o -c "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/FUCYOUEL/code/exampleapp.cc"

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.i"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/FUCYOUEL" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/FUCYOUEL/code/exampleapp.cc" > CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.i

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.s"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/FUCYOUEL" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/FUCYOUEL/code/exampleapp.cc" -o CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.s

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o.requires:

.PHONY : projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o.requires

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o.provides: projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o.requires
	$(MAKE) -f projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/build.make projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o.provides.build
.PHONY : projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o.provides

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o.provides.build: projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o


projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o: projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/flags.make
projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o: ../projects/FUCYOUEL/code/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/FUCYOUEL" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FUCYOUEL.dir/code/main.cc.o -c "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/FUCYOUEL/code/main.cc"

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FUCYOUEL.dir/code/main.cc.i"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/FUCYOUEL" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/FUCYOUEL/code/main.cc" > CMakeFiles/FUCYOUEL.dir/code/main.cc.i

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FUCYOUEL.dir/code/main.cc.s"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/FUCYOUEL" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/FUCYOUEL/code/main.cc" -o CMakeFiles/FUCYOUEL.dir/code/main.cc.s

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o.requires:

.PHONY : projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o.requires

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o.provides: projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o.requires
	$(MAKE) -f projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/build.make projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o.provides.build
.PHONY : projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o.provides

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o.provides.build: projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o


# Object files for target FUCYOUEL
FUCYOUEL_OBJECTS = \
"CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o" \
"CMakeFiles/FUCYOUEL.dir/code/main.cc.o"

# External object files for target FUCYOUEL
FUCYOUEL_EXTERNAL_OBJECTS =

projects/FUCYOUEL/FUCYOUEL: projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o
projects/FUCYOUEL/FUCYOUEL: projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o
projects/FUCYOUEL/FUCYOUEL: projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/build.make
projects/FUCYOUEL/FUCYOUEL: engine/core/libcore.a
projects/FUCYOUEL/FUCYOUEL: engine/render/librender.a
projects/FUCYOUEL/FUCYOUEL: exts/glew/libglew.a
projects/FUCYOUEL/FUCYOUEL: exts/glfw-3.1.1/src/libglfw3.a
projects/FUCYOUEL/FUCYOUEL: projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable FUCYOUEL"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/FUCYOUEL" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FUCYOUEL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/build: projects/FUCYOUEL/FUCYOUEL

.PHONY : projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/build

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/requires: projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/exampleapp.cc.o.requires
projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/requires: projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/code/main.cc.o.requires

.PHONY : projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/requires

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/clean:
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/FUCYOUEL" && $(CMAKE_COMMAND) -P CMakeFiles/FUCYOUEL.dir/cmake_clean.cmake
.PHONY : projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/clean

projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/depend:
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/FUCYOUEL" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/FUCYOUEL" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : projects/FUCYOUEL/CMakeFiles/FUCYOUEL.dir/depend

