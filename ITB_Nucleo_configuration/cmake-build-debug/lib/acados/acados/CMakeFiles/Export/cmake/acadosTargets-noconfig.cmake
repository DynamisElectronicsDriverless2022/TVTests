#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "acados" for configuration ""
set_property(TARGET acados APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(acados PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "C"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libacados.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS acados )
list(APPEND _IMPORT_CHECK_FILES_FOR_acados "${_IMPORT_PREFIX}/lib/libacados.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
