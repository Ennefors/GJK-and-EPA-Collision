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
include projects/example/CMakeFiles/example.dir/depend.make

# Include the progress variables for this target.
include projects/example/CMakeFiles/example.dir/progress.make

# Include the compile flags for this target's objects.
include projects/example/CMakeFiles/example.dir/flags.make

projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o: projects/example/CMakeFiles/example.dir/flags.make
projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o: ../projects/example/code/exampleapp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/code/exampleapp.cc.o -c "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/exampleapp.cc"

projects/example/CMakeFiles/example.dir/code/exampleapp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/code/exampleapp.cc.i"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/exampleapp.cc" > CMakeFiles/example.dir/code/exampleapp.cc.i

projects/example/CMakeFiles/example.dir/code/exampleapp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/code/exampleapp.cc.s"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/exampleapp.cc" -o CMakeFiles/example.dir/code/exampleapp.cc.s

projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o.requires:

.PHONY : projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o.requires

projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o.provides: projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o.requires
	$(MAKE) -f projects/example/CMakeFiles/example.dir/build.make projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o.provides.build
.PHONY : projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o.provides

projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o.provides.build: projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o


projects/example/CMakeFiles/example.dir/code/main.cc.o: projects/example/CMakeFiles/example.dir/flags.make
projects/example/CMakeFiles/example.dir/code/main.cc.o: ../projects/example/code/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object projects/example/CMakeFiles/example.dir/code/main.cc.o"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/code/main.cc.o -c "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/main.cc"

projects/example/CMakeFiles/example.dir/code/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/code/main.cc.i"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/main.cc" > CMakeFiles/example.dir/code/main.cc.i

projects/example/CMakeFiles/example.dir/code/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/code/main.cc.s"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/main.cc" -o CMakeFiles/example.dir/code/main.cc.s

projects/example/CMakeFiles/example.dir/code/main.cc.o.requires:

.PHONY : projects/example/CMakeFiles/example.dir/code/main.cc.o.requires

projects/example/CMakeFiles/example.dir/code/main.cc.o.provides: projects/example/CMakeFiles/example.dir/code/main.cc.o.requires
	$(MAKE) -f projects/example/CMakeFiles/example.dir/build.make projects/example/CMakeFiles/example.dir/code/main.cc.o.provides.build
.PHONY : projects/example/CMakeFiles/example.dir/code/main.cc.o.provides

projects/example/CMakeFiles/example.dir/code/main.cc.o.provides.build: projects/example/CMakeFiles/example.dir/code/main.cc.o


projects/example/CMakeFiles/example.dir/code/Collison.cpp.o: projects/example/CMakeFiles/example.dir/flags.make
projects/example/CMakeFiles/example.dir/code/Collison.cpp.o: ../projects/example/code/Collison.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object projects/example/CMakeFiles/example.dir/code/Collison.cpp.o"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/code/Collison.cpp.o -c "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/Collison.cpp"

projects/example/CMakeFiles/example.dir/code/Collison.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/code/Collison.cpp.i"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/Collison.cpp" > CMakeFiles/example.dir/code/Collison.cpp.i

projects/example/CMakeFiles/example.dir/code/Collison.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/code/Collison.cpp.s"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/Collison.cpp" -o CMakeFiles/example.dir/code/Collison.cpp.s

projects/example/CMakeFiles/example.dir/code/Collison.cpp.o.requires:

.PHONY : projects/example/CMakeFiles/example.dir/code/Collison.cpp.o.requires

projects/example/CMakeFiles/example.dir/code/Collison.cpp.o.provides: projects/example/CMakeFiles/example.dir/code/Collison.cpp.o.requires
	$(MAKE) -f projects/example/CMakeFiles/example.dir/build.make projects/example/CMakeFiles/example.dir/code/Collison.cpp.o.provides.build
.PHONY : projects/example/CMakeFiles/example.dir/code/Collison.cpp.o.provides

projects/example/CMakeFiles/example.dir/code/Collison.cpp.o.provides.build: projects/example/CMakeFiles/example.dir/code/Collison.cpp.o


projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o: projects/example/CMakeFiles/example.dir/flags.make
projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o: ../projects/example/code/GraphicsNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/code/GraphicsNode.cpp.o -c "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/GraphicsNode.cpp"

projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/code/GraphicsNode.cpp.i"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/GraphicsNode.cpp" > CMakeFiles/example.dir/code/GraphicsNode.cpp.i

projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/code/GraphicsNode.cpp.s"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/GraphicsNode.cpp" -o CMakeFiles/example.dir/code/GraphicsNode.cpp.s

projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o.requires:

.PHONY : projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o.requires

projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o.provides: projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o.requires
	$(MAKE) -f projects/example/CMakeFiles/example.dir/build.make projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o.provides.build
.PHONY : projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o.provides

projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o.provides.build: projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o


projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o: projects/example/CMakeFiles/example.dir/flags.make
projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o: ../projects/example/code/PlaneSweep.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/code/PlaneSweep.cpp.o -c "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/PlaneSweep.cpp"

projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/code/PlaneSweep.cpp.i"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/PlaneSweep.cpp" > CMakeFiles/example.dir/code/PlaneSweep.cpp.i

projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/code/PlaneSweep.cpp.s"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/PlaneSweep.cpp" -o CMakeFiles/example.dir/code/PlaneSweep.cpp.s

projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o.requires:

.PHONY : projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o.requires

projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o.provides: projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o.requires
	$(MAKE) -f projects/example/CMakeFiles/example.dir/build.make projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o.provides.build
.PHONY : projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o.provides

projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o.provides.build: projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o


projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o: projects/example/CMakeFiles/example.dir/flags.make
projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o: ../projects/example/code/Raycast.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/code/Raycast.cpp.o -c "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/Raycast.cpp"

projects/example/CMakeFiles/example.dir/code/Raycast.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/code/Raycast.cpp.i"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/Raycast.cpp" > CMakeFiles/example.dir/code/Raycast.cpp.i

projects/example/CMakeFiles/example.dir/code/Raycast.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/code/Raycast.cpp.s"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/Raycast.cpp" -o CMakeFiles/example.dir/code/Raycast.cpp.s

projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o.requires:

.PHONY : projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o.requires

projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o.provides: projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o.requires
	$(MAKE) -f projects/example/CMakeFiles/example.dir/build.make projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o.provides.build
.PHONY : projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o.provides

projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o.provides.build: projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o


projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o: projects/example/CMakeFiles/example.dir/flags.make
projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o: ../projects/example/code/ShaderObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/code/ShaderObject.cpp.o -c "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/ShaderObject.cpp"

projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/code/ShaderObject.cpp.i"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/ShaderObject.cpp" > CMakeFiles/example.dir/code/ShaderObject.cpp.i

projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/code/ShaderObject.cpp.s"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/ShaderObject.cpp" -o CMakeFiles/example.dir/code/ShaderObject.cpp.s

projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o.requires:

.PHONY : projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o.requires

projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o.provides: projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o.requires
	$(MAKE) -f projects/example/CMakeFiles/example.dir/build.make projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o.provides.build
.PHONY : projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o.provides

projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o.provides.build: projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o


projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o: projects/example/CMakeFiles/example.dir/flags.make
projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o: ../projects/example/code/meshResource.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/code/meshResource.cpp.o -c "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/meshResource.cpp"

projects/example/CMakeFiles/example.dir/code/meshResource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/code/meshResource.cpp.i"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/meshResource.cpp" > CMakeFiles/example.dir/code/meshResource.cpp.i

projects/example/CMakeFiles/example.dir/code/meshResource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/code/meshResource.cpp.s"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/meshResource.cpp" -o CMakeFiles/example.dir/code/meshResource.cpp.s

projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o.requires:

.PHONY : projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o.requires

projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o.provides: projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o.requires
	$(MAKE) -f projects/example/CMakeFiles/example.dir/build.make projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o.provides.build
.PHONY : projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o.provides

projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o.provides.build: projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o


projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o: projects/example/CMakeFiles/example.dir/flags.make
projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o: ../projects/example/code/textureResource.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/code/textureResource.cpp.o -c "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/textureResource.cpp"

projects/example/CMakeFiles/example.dir/code/textureResource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/code/textureResource.cpp.i"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/textureResource.cpp" > CMakeFiles/example.dir/code/textureResource.cpp.i

projects/example/CMakeFiles/example.dir/code/textureResource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/code/textureResource.cpp.s"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example/code/textureResource.cpp" -o CMakeFiles/example.dir/code/textureResource.cpp.s

projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o.requires:

.PHONY : projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o.requires

projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o.provides: projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o.requires
	$(MAKE) -f projects/example/CMakeFiles/example.dir/build.make projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o.provides.build
.PHONY : projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o.provides

projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o.provides.build: projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o


# Object files for target example
example_OBJECTS = \
"CMakeFiles/example.dir/code/exampleapp.cc.o" \
"CMakeFiles/example.dir/code/main.cc.o" \
"CMakeFiles/example.dir/code/Collison.cpp.o" \
"CMakeFiles/example.dir/code/GraphicsNode.cpp.o" \
"CMakeFiles/example.dir/code/PlaneSweep.cpp.o" \
"CMakeFiles/example.dir/code/Raycast.cpp.o" \
"CMakeFiles/example.dir/code/ShaderObject.cpp.o" \
"CMakeFiles/example.dir/code/meshResource.cpp.o" \
"CMakeFiles/example.dir/code/textureResource.cpp.o"

# External object files for target example
example_EXTERNAL_OBJECTS =

projects/example/example: projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o
projects/example/example: projects/example/CMakeFiles/example.dir/code/main.cc.o
projects/example/example: projects/example/CMakeFiles/example.dir/code/Collison.cpp.o
projects/example/example: projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o
projects/example/example: projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o
projects/example/example: projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o
projects/example/example: projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o
projects/example/example: projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o
projects/example/example: projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o
projects/example/example: projects/example/CMakeFiles/example.dir/build.make
projects/example/example: engine/core/libcore.a
projects/example/example: engine/render/librender.a
projects/example/example: exts/glew/libglew.a
projects/example/example: exts/glfw-3.1.1/src/libglfw3.a
projects/example/example: projects/example/CMakeFiles/example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable example"
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
projects/example/CMakeFiles/example.dir/build: projects/example/example

.PHONY : projects/example/CMakeFiles/example.dir/build

projects/example/CMakeFiles/example.dir/requires: projects/example/CMakeFiles/example.dir/code/exampleapp.cc.o.requires
projects/example/CMakeFiles/example.dir/requires: projects/example/CMakeFiles/example.dir/code/main.cc.o.requires
projects/example/CMakeFiles/example.dir/requires: projects/example/CMakeFiles/example.dir/code/Collison.cpp.o.requires
projects/example/CMakeFiles/example.dir/requires: projects/example/CMakeFiles/example.dir/code/GraphicsNode.cpp.o.requires
projects/example/CMakeFiles/example.dir/requires: projects/example/CMakeFiles/example.dir/code/PlaneSweep.cpp.o.requires
projects/example/CMakeFiles/example.dir/requires: projects/example/CMakeFiles/example.dir/code/Raycast.cpp.o.requires
projects/example/CMakeFiles/example.dir/requires: projects/example/CMakeFiles/example.dir/code/ShaderObject.cpp.o.requires
projects/example/CMakeFiles/example.dir/requires: projects/example/CMakeFiles/example.dir/code/meshResource.cpp.o.requires
projects/example/CMakeFiles/example.dir/requires: projects/example/CMakeFiles/example.dir/code/textureResource.cpp.o.requires

.PHONY : projects/example/CMakeFiles/example.dir/requires

projects/example/CMakeFiles/example.dir/clean:
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" && $(CMAKE_COMMAND) -P CMakeFiles/example.dir/cmake_clean.cmake
.PHONY : projects/example/CMakeFiles/example.dir/clean

projects/example/CMakeFiles/example.dir/depend:
	cd "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/projects/example" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example" "/home/bill/wilenn-5/S0009D/lab-env-master (another copy)/cmake-build-debug/projects/example/CMakeFiles/example.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : projects/example/CMakeFiles/example.dir/depend

