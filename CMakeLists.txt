# COPYRIGHT (C) Florian Wolters 2014
#
# Author: Florian Wolters <wolters.fl@gmail.com>

cmake_minimum_required (VERSION 2.6)

set (PROJECT_NAME "arkanoid")
set (PROJECT_TYPE "CXX")
set (GNUCXX_MINIMUM_VERSION "4.8")
set (CXX_STANDARD "c++11")
set (BUILD_STATIC TRUE)
set (BUILD_VERBOSE TRUE)
set (BUILD_DIR "build")
set (HEADER_DIR "include")
set (SOURCE_DIR "src")
set (EXECUTABLE_PATH "${BUILD_DIR}/${PROJECT_NAME}")

project (${PROJECT_NAME} ${PROJECT_TYPE})

if (CMAKE_BUILD_TYPE STREQUAL "")
  set (CMAKE_BUILD_TYPE Debug)
endif()

if (CMAKE_COMPILER_IS_GNUCXX)
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS GNUCXX_MINIMUM_VERSION)
    message (FATAL_ERROR "GCC version must be at least ${GNUCXX_MINIMUM_VERSION}!")
  endif()
else()
  message (FATAL_ERROR "Invalid compiler!")
endif()

set (CMAKE_VERBOSE_MAKEFILE ${BUILD_VERBOSE})
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=${CXX_STANDARD} -Wall -Wextra -Werror -pedantic")

file (GLOB SOURCE_FILES
  "${HEADER_DIR}/*.h"
  "${SOURCE_DIR}/*.cc"
)
include_directories (${HEADER_DIR})
add_executable (${EXECUTABLE_PATH} ${SOURCE_FILES})

# Find SFML
set (SFML_ROOT "../SFML-2.1")
set (CMAKE_MODULE_PATH "${SFML_ROOT}/cmake/Modules" ${CMAKE_MODULE_PATH})
set (SFML_STATIC_LIBRARIES ${BUILD_STATIC})
find_package (SFML 2 COMPONENTS audio graphics window system)

if (SFML_FOUND)
  include_directories (${SFML_INCLUDE_DIR})
  target_link_libraries (${EXECUTABLE_PATH} ${SFML_LIBRARIES})
endif()
