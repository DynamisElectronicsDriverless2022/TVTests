# Install script for directory: D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Users/giuse/scoop/apps/gcc-arm-none-eabi/current/bin/arm-none-eabi-objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/lib/acados/external/blasfeo/libblasfeo.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/blasfeoConfig.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/blasfeoConfig.cmake"
         "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/lib/acados/external/blasfeo/CMakeFiles/Export/cmake/blasfeoConfig.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/blasfeoConfig-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/blasfeoConfig.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/lib/acados/external/blasfeo/CMakeFiles/Export/cmake/blasfeoConfig.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/lib/acados/external/blasfeo/CMakeFiles/Export/cmake/blasfeoConfig-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/blasfeo/include" TYPE FILE FILES
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_block_size.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_common.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_d_aux.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_d_aux_ext_dep.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_d_aux_ext_dep_ref.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_d_aux_old.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_d_aux_ref.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_d_aux_test.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_d_blas.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_d_blas_api.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_d_blasfeo_api.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_d_blasfeo_api_ref.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_d_blasfeo_ref_api.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_d_kernel.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_i_aux_ext_dep.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_m_aux.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_memory.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_naming.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_processor_features.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_s_aux.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_s_aux_ext_dep.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_s_aux_ext_dep_ref.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_s_aux_old.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_s_aux_ref.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_s_aux_test.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_s_blas.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_s_blas_api.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_s_blasfeo_api.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_s_blasfeo_api_ref.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_s_blasfeo_ref_api.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_s_kernel.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_stdlib.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_target.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_timing.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/blasfeo_v_aux_ext_dep.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/d_blas.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/d_blas_64.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/s_blas.h"
    "D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/acados/external/blasfeo/include/s_blas_64.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/DynamisGit/Timing/TVTests/ITB_Nucleo_configuration/cmake-build-debug/lib/acados/external/blasfeo/examples/cmake_install.cmake")

endif()

