# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = D:/CMake/bin/cmake.exe

# The command to remove a file.
RM = D:/CMake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/DynamisGit/Timing/TVTests

# Include any dependencies generated for this target.
include lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/progress.make

# Include the compile flags for this target's objects.
include lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/flags.make

lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/getting_started.c.obj: lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/flags.make
lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/getting_started.c.obj: ITB_Nucleo_configuration/acados/external/blasfeo/examples/getting_started.c
lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/getting_started.c.obj: lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/DynamisGit/Timing/TVTests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/getting_started.c.obj"
	cd D:/DynamisGit/Timing/TVTests/lib/acados/external/blasfeo/examples && C:/Users/giuse/scoop/apps/gcc-arm-none-eabi/current/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/getting_started.c.obj -MF CMakeFiles/getting_started.dir/getting_started.c.obj.d -o CMakeFiles/getting_started.dir/getting_started.c.obj -c D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/examples/getting_started.c

lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/getting_started.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/getting_started.dir/getting_started.c.i"
	cd D:/DynamisGit/Timing/TVTests/lib/acados/external/blasfeo/examples && C:/Users/giuse/scoop/apps/gcc-arm-none-eabi/current/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/examples/getting_started.c > CMakeFiles/getting_started.dir/getting_started.c.i

lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/getting_started.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/getting_started.dir/getting_started.c.s"
	cd D:/DynamisGit/Timing/TVTests/lib/acados/external/blasfeo/examples && C:/Users/giuse/scoop/apps/gcc-arm-none-eabi/current/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/examples/getting_started.c -o CMakeFiles/getting_started.dir/getting_started.c.s

# Object files for target getting_started
getting_started_OBJECTS = \
"CMakeFiles/getting_started.dir/getting_started.c.obj"

# External object files for target getting_started
getting_started_EXTERNAL_OBJECTS =

lib/acados/external/blasfeo/examples/getting_started: lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/getting_started.c.obj
lib/acados/external/blasfeo/examples/getting_started: lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/build.make
lib/acados/external/blasfeo/examples/getting_started: lib/acados/external/blasfeo/libblasfeo.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/DynamisGit/Timing/TVTests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable getting_started"
	cd D:/DynamisGit/Timing/TVTests/lib/acados/external/blasfeo/examples && C:/Users/giuse/scoop/apps/gcc-arm-none-eabi/current/bin/arm-none-eabi-gcc.exe  -std=c99 -Wall -fdiagnostics-show-option -Wno-error -w -DLA_HIGH_PERFORMANCE -DMF_PANELMAJ -DK_MAX_STACK=300 -DUSE_C99_MATH -DEXT_DEP -DOS_WINDOWS -DEXTERNAL_BLAS_NONE -O2 -fPIC -DTARGET_GENERIC  -O3 -DNDEBUG -mfloat-abi=hard -mfpu=fpv5-d16 $(getting_started_OBJECTS) $(getting_started_EXTERNAL_OBJECTS) -o getting_started  ../libblasfeo.a -lm 

# Rule to build all files generated by this target.
lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/build: lib/acados/external/blasfeo/examples/getting_started
.PHONY : lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/build

lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/clean:
	cd D:/DynamisGit/Timing/TVTests/lib/acados/external/blasfeo/examples && $(CMAKE_COMMAND) -P CMakeFiles/getting_started.dir/cmake_clean.cmake
.PHONY : lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/clean

lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/examples D:/DynamisGit/Timing/TVTests D:/DynamisGit/Timing/TVTests/lib/acados/external/blasfeo/examples D:/DynamisGit/Timing/TVTests/lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/acados/external/blasfeo/examples/CMakeFiles/getting_started.dir/depend

