# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/horseluis/HorseDev/Graphics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/horseluis/HorseDev/Graphics/build

# Include any dependencies generated for this target.
include CMakeFiles/Cube_project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Cube_project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Cube_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cube_project.dir/flags.make

CMakeFiles/Cube_project.dir/src/main.cpp.o: CMakeFiles/Cube_project.dir/flags.make
CMakeFiles/Cube_project.dir/src/main.cpp.o: /home/horseluis/HorseDev/Graphics/src/main.cpp
CMakeFiles/Cube_project.dir/src/main.cpp.o: CMakeFiles/Cube_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/horseluis/HorseDev/Graphics/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cube_project.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cube_project.dir/src/main.cpp.o -MF CMakeFiles/Cube_project.dir/src/main.cpp.o.d -o CMakeFiles/Cube_project.dir/src/main.cpp.o -c /home/horseluis/HorseDev/Graphics/src/main.cpp

CMakeFiles/Cube_project.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Cube_project.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/horseluis/HorseDev/Graphics/src/main.cpp > CMakeFiles/Cube_project.dir/src/main.cpp.i

CMakeFiles/Cube_project.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Cube_project.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/horseluis/HorseDev/Graphics/src/main.cpp -o CMakeFiles/Cube_project.dir/src/main.cpp.s

CMakeFiles/Cube_project.dir/src/openConf.cpp.o: CMakeFiles/Cube_project.dir/flags.make
CMakeFiles/Cube_project.dir/src/openConf.cpp.o: /home/horseluis/HorseDev/Graphics/src/openConf.cpp
CMakeFiles/Cube_project.dir/src/openConf.cpp.o: CMakeFiles/Cube_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/horseluis/HorseDev/Graphics/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Cube_project.dir/src/openConf.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cube_project.dir/src/openConf.cpp.o -MF CMakeFiles/Cube_project.dir/src/openConf.cpp.o.d -o CMakeFiles/Cube_project.dir/src/openConf.cpp.o -c /home/horseluis/HorseDev/Graphics/src/openConf.cpp

CMakeFiles/Cube_project.dir/src/openConf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Cube_project.dir/src/openConf.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/horseluis/HorseDev/Graphics/src/openConf.cpp > CMakeFiles/Cube_project.dir/src/openConf.cpp.i

CMakeFiles/Cube_project.dir/src/openConf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Cube_project.dir/src/openConf.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/horseluis/HorseDev/Graphics/src/openConf.cpp -o CMakeFiles/Cube_project.dir/src/openConf.cpp.s

CMakeFiles/Cube_project.dir/src/texLoader.cpp.o: CMakeFiles/Cube_project.dir/flags.make
CMakeFiles/Cube_project.dir/src/texLoader.cpp.o: /home/horseluis/HorseDev/Graphics/src/texLoader.cpp
CMakeFiles/Cube_project.dir/src/texLoader.cpp.o: CMakeFiles/Cube_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/horseluis/HorseDev/Graphics/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Cube_project.dir/src/texLoader.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cube_project.dir/src/texLoader.cpp.o -MF CMakeFiles/Cube_project.dir/src/texLoader.cpp.o.d -o CMakeFiles/Cube_project.dir/src/texLoader.cpp.o -c /home/horseluis/HorseDev/Graphics/src/texLoader.cpp

CMakeFiles/Cube_project.dir/src/texLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Cube_project.dir/src/texLoader.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/horseluis/HorseDev/Graphics/src/texLoader.cpp > CMakeFiles/Cube_project.dir/src/texLoader.cpp.i

CMakeFiles/Cube_project.dir/src/texLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Cube_project.dir/src/texLoader.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/horseluis/HorseDev/Graphics/src/texLoader.cpp -o CMakeFiles/Cube_project.dir/src/texLoader.cpp.s

CMakeFiles/Cube_project.dir/includes/glad.c.o: CMakeFiles/Cube_project.dir/flags.make
CMakeFiles/Cube_project.dir/includes/glad.c.o: /home/horseluis/HorseDev/Graphics/includes/glad.c
CMakeFiles/Cube_project.dir/includes/glad.c.o: CMakeFiles/Cube_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/horseluis/HorseDev/Graphics/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Cube_project.dir/includes/glad.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Cube_project.dir/includes/glad.c.o -MF CMakeFiles/Cube_project.dir/includes/glad.c.o.d -o CMakeFiles/Cube_project.dir/includes/glad.c.o -c /home/horseluis/HorseDev/Graphics/includes/glad.c

CMakeFiles/Cube_project.dir/includes/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Cube_project.dir/includes/glad.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/horseluis/HorseDev/Graphics/includes/glad.c > CMakeFiles/Cube_project.dir/includes/glad.c.i

CMakeFiles/Cube_project.dir/includes/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Cube_project.dir/includes/glad.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/horseluis/HorseDev/Graphics/includes/glad.c -o CMakeFiles/Cube_project.dir/includes/glad.c.s

# Object files for target Cube_project
Cube_project_OBJECTS = \
"CMakeFiles/Cube_project.dir/src/main.cpp.o" \
"CMakeFiles/Cube_project.dir/src/openConf.cpp.o" \
"CMakeFiles/Cube_project.dir/src/texLoader.cpp.o" \
"CMakeFiles/Cube_project.dir/includes/glad.c.o"

# External object files for target Cube_project
Cube_project_EXTERNAL_OBJECTS =

Cube_project: CMakeFiles/Cube_project.dir/src/main.cpp.o
Cube_project: CMakeFiles/Cube_project.dir/src/openConf.cpp.o
Cube_project: CMakeFiles/Cube_project.dir/src/texLoader.cpp.o
Cube_project: CMakeFiles/Cube_project.dir/includes/glad.c.o
Cube_project: CMakeFiles/Cube_project.dir/build.make
Cube_project: /usr/lib/x86_64-linux-gnu/libGLX.so
Cube_project: /usr/lib/x86_64-linux-gnu/libOpenGL.so
Cube_project: CMakeFiles/Cube_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/horseluis/HorseDev/Graphics/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Cube_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Cube_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cube_project.dir/build: Cube_project
.PHONY : CMakeFiles/Cube_project.dir/build

CMakeFiles/Cube_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Cube_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Cube_project.dir/clean

CMakeFiles/Cube_project.dir/depend:
	cd /home/horseluis/HorseDev/Graphics/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/horseluis/HorseDev/Graphics /home/horseluis/HorseDev/Graphics /home/horseluis/HorseDev/Graphics/build /home/horseluis/HorseDev/Graphics/build /home/horseluis/HorseDev/Graphics/build/CMakeFiles/Cube_project.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Cube_project.dir/depend

