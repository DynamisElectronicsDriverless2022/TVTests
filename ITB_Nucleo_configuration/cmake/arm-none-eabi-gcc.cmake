set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)

if(MINGW OR CYGWIN OR WIN32)
    set(UTIL_SEARCH_CMD where)
elseif(UNIX OR APPLE)
    set(UTIL_SEARCH_CMD which)
endif()

set(TOOLCHAIN_PREFIX arm-none-eabi-)

if(NOT DEFINED ARM_TOOLCHAIN_DIR AND DEFINED ENV{ARM_TOOLCHAIN_DIR})
    set(ARM_TOOLCHAIN_DIR $ENV{ARM_TOOLCHAIN_DIR})
endif()

if(NOT DEFINED ARM_TOOLCHAIN_DIR)
    execute_process(
      COMMAND ${UTIL_SEARCH_CMD} ${TOOLCHAIN_PREFIX}gcc
      OUTPUT_VARIABLE BINUTILS_PATH
      OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    if(BINUTILS_PATH STREQUAL "")
        message(FATAL_ERROR "Could not find toolchain")
    endif()

    get_filename_component(ARM_TOOLCHAIN_DIR ${BINUTILS_PATH} DIRECTORY)
endif()

message("Toolchain directory: ${ARM_TOOLCHAIN_DIR}")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_C_COMPILER ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}gcc.exe)
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_CXX_COMPILER ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}g++.exe)

set(CMAKE_OBJCOPY ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}objcopy CACHE INTERNAL "objcopy tool")
set(CMAKE_SIZE_UTIL ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}size CACHE INTERNAL "size tool")

set(CMAKE_AR ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}ar)
set(CMAKE_OBJDUMP ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}objdump)
set(CMAKE_GDB ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}gdb)
set(SIZE ${CMAKE_SIZE_UTIL})

set(CMAKE_FIND_ROOT_PATH ${ARM_TOOLCHAIN_DIR})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)