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
include exts/glew/CMakeFiles/glew.dir/depend.make

# Include the progress variables for this target.
include exts/glew/CMakeFiles/glew.dir/progress.make

# Include the compile flags for this target's objects.
include exts/glew/CMakeFiles/glew.dir/flags.make

exts/glew/CMakeFiles/glew.dir/src/glew.c.o: exts/glew/CMakeFiles/glew.dir/flags.make
exts/glew/CMakeFiles/glew.dir/src/glew.c.o: ../exts/glew/src/glew.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object exts/glew/CMakeFiles/glew.dir/src/glew.c.o"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/exts/glew" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glew.dir/src/glew.c.o   -c "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/exts/glew/src/glew.c"

exts/glew/CMakeFiles/glew.dir/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glew.dir/src/glew.c.i"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/exts/glew" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/exts/glew/src/glew.c" > CMakeFiles/glew.dir/src/glew.c.i

exts/glew/CMakeFiles/glew.dir/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glew.dir/src/glew.c.s"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/exts/glew" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/exts/glew/src/glew.c" -o CMakeFiles/glew.dir/src/glew.c.s

exts/glew/CMakeFiles/glew.dir/src/glew.c.o.requires:

.PHONY : exts/glew/CMakeFiles/glew.dir/src/glew.c.o.requires

exts/glew/CMakeFiles/glew.dir/src/glew.c.o.provides: exts/glew/CMakeFiles/glew.dir/src/glew.c.o.requires
	$(MAKE) -f exts/glew/CMakeFiles/glew.dir/build.make exts/glew/CMakeFiles/glew.dir/src/glew.c.o.provides.build
.PHONY : exts/glew/CMakeFiles/glew.dir/src/glew.c.o.provides

exts/glew/CMakeFiles/glew.dir/src/glew.c.o.provides.build: exts/glew/CMakeFiles/glew.dir/src/glew.c.o


# Object files for target glew
glew_OBJECTS = \
"CMakeFiles/glew.dir/src/glew.c.o"

# External object files for target glew
glew_EXTERNAL_OBJECTS =

exts/glew/libglew.a: exts/glew/CMakeFiles/glew.dir/src/glew.c.o
exts/glew/libglew.a: exts/glew/CMakeFiles/glew.dir/build.make
exts/glew/libglew.a: exts/glew/CMakeFiles/glew.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglew.a"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/exts/glew" && $(CMAKE_COMMAND) -P CMakeFiles/glew.dir/cmake_clean_target.cmake
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/exts/glew" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glew.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
exts/glew/CMakeFiles/glew.dir/build: exts/glew/libglew.a

.PHONY : exts/glew/CMakeFiles/glew.dir/build

exts/glew/CMakeFiles/glew.dir/requires: exts/glew/CMakeFiles/glew.dir/src/glew.c.o.requires

.PHONY : exts/glew/CMakeFiles/glew.dir/requires

exts/glew/CMakeFiles/glew.dir/clean:
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/exts/glew" && $(CMAKE_COMMAND) -P CMakeFiles/glew.dir/cmake_clean.cmake
.PHONY : exts/glew/CMakeFiles/glew.dir/clean

exts/glew/CMakeFiles/glew.dir/depend:
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/exts/glew" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/exts/glew" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/exts/glew/CMakeFiles/glew.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : exts/glew/CMakeFiles/glew.dir/depend

