#
# Copyright 2019 Gianluca Frison, Dimitris Kouzoupis, Robin Verschueren,
# Andrea Zanelli, Niels van Duijkeren, Jonathan Frey, Tommaso Sartor,
# Branimir Novoselnik, Rien Quirynen, Rezart Qelibari, Dang Doan,
# Jonas Koenemann, Yutao Chen, Tobias Schöls, Jonas Schlagenhauf, Moritz Diehl
#
# This file is part of acados.
#
# The 2-Clause BSD License
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
# this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.;
#

# Enabled external modules
set(ACADOS_WITH_HPMPC OFF)
set(ACADOS_WITH_QORE OFF)
set(ACADOS_WITH_QPOASES OFF)
set(ACADOS_WITH_QPDUNES OFF)
set(ACADOS_WITH_OSQP OFF)
set(ACADOS_WITH_OOQP OFF)

# Add acados CMake folder to CMake prefix and module path
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/../") # for *Config.cmake
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")     # for FindOpenBLAS, FindFortranLibs

# Find the enabled external modules
find_package(blasfeo)
find_package(hpipm)

if(ACADOS_WITH_QPOASES)
    find_package(qpOASES_e)
endif()

if(ACADOS_WITH_HPMPC)
    find_package(hpmpc)
endif()

if(ACADOS_WITH_QPDUNES)
    find_package(qpdunes)
endif()

if(ACADOS_WITH_QORE)
    find_package(qore)
endif()

if(ACADOS_WITH_OOQP)
    find_package(ooqp)
endif()

find_package(OpenBLAS)
add_library(openblas UNKNOWN IMPORTED)
set_property(TARGET openblas PROPERTY IMPORTED_LOCATION ${OpenBLAS_LIB})

find_package(FortranLibs)
add_library(gfortran UNKNOWN IMPORTED)
set_property(TARGET gfortran PROPERTY IMPORTED_LOCATION ${FORTRAN_LIBRARY})

include("${CMAKE_CURRENT_LIST_DIR}/acadosTargets.cmake")
