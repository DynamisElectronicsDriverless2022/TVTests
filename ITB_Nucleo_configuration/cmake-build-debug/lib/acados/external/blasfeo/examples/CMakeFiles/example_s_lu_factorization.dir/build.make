# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "D:/Clion/CLion 2021.3.3/bin/cmake/win/bin/cmake.exe"

# The command to remove a file.
RM = "D:/Clion/CLion 2021.3.3/bin/cmake/win/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug

# Include any dependencies generated for this target.
include lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/progress.make

# Include the compile flags for this target's objects.
include lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/flags.make

lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.obj: lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/flags.make
lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.obj: C:/Users/giuse/Desktop/Timing/TVTests/acados/external/blasfeo/examples/example_s_lu_factorization.c
lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.obj: lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.obj"
	cd C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/lib/acados/external/blasfeo/examples && C:/Users/giuse/scoop/apps/gcc-arm-none-eabi/current/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.obj -MF CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.obj.d -o CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.obj -c C:/Users/giuse/Desktop/Timing/TVTests/acados/external/blasfeo/examples/example_s_lu_factorization.c

lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.i"
	cd C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/lib/acados/external/blasfeo/examples && C:/Users/giuse/scoop/apps/gcc-arm-none-eabi/current/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/giuse/Desktop/Timing/TVTests/acados/external/blasfeo/examples/example_s_lu_factorization.c > CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.i

lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.s"
	cd C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/lib/acados/external/blasfeo/examples && C:/Users/giuse/scoop/apps/gcc-arm-none-eabi/current/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/giuse/Desktop/Timing/TVTests/acados/external/blasfeo/examples/example_s_lu_factorization.c -o CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.s

# Object files for target example_s_lu_factorization
example_s_lu_factorization_OBJECTS = \
"CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.obj"

# External object files for target example_s_lu_factorization
example_s_lu_factorization_EXTERNAL_OBJECTS =

lib/acados/external/blasfeo/examples/example_s_lu_factorization: lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/example_s_lu_factorization.c.obj
lib/acados/external/blasfeo/examples/example_s_lu_factorization: lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/build.make
lib/acados/external/blasfeo/examples/example_s_lu_factorization: lib/acados/external/blasfeo/libblasfeo.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable example_s_lu_factorization"
	cd C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/lib/acados/external/blasfeo/examples && C:/Users/giuse/scoop/apps/gcc-arm-none-eabi/current/bin/arm-none-eabi-gcc.exe  -std=c99 -Wall -fdiagnostics-show-option -Wno-error -w -DLA_HIGH_PERFORMANCE -DMF_PANELMAJ -DK_MAX_STACK=300 -DUSE_C99_MATH -DEXT_DEP -DOS_WINDOWS -DEXTERNAL_BLAS_NONE -O2 -fPIC -DTARGET_GENERIC  -O3 -DNDEBUG $(example_s_lu_factorization_OBJECTS) $(example_s_lu_factorization_EXTERNAL_OBJECTS) -o example_s_lu_factorization  ../libblasfeo.a -lm 

# Rule to build all files generated by this target.
lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/build: lib/acados/external/blasfeo/examples/example_s_lu_factorization
.PHONY : lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/build

lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/clean:
	cd C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/lib/acados/external/blasfeo/examples && $(CMAKE_COMMAND) -P CMakeFiles/example_s_lu_factorization.dir/cmake_clean.cmake
.PHONY : lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/clean

lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration C:/Users/giuse/Desktop/Timing/TVTests/acados/external/blasfeo/examples C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/lib/acados/external/blasfeo/examples C:/Users/giuse/Desktop/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/acados/external/blasfeo/examples/CMakeFiles/example_s_lu_factorization.dir/depend

