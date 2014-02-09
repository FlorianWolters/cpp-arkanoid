# COPYRIGHT (C) Florian Wolters 2014
#
# Author: Florian Wolters <wolters.fl@gmail.com>

cmake_minimum_required (VERSION 2.8.9 FATAL_ERROR)

set (PROJECT_NAME "arkanoid")
set (GNUCXX_MINIMUM_VERSION "4.8.2")
set (CXX_STANDARD "c++11")
set (GNUCXX_FLAGS "-Werror -Wfatal-errors -pedantic-errors -Wall -Wextra -Wdouble-promotion -Wmissing-include-dirs -Wswitch-default -Weffc++")

# Directory paths to external packages.
set (EXTERNAL_PACKAGE_ROOT "D:/dev")
set (GTEST_ROOT "${EXTERNAL_PACKAGE_ROOT}/gtest-1.7.0")
set (GMOCK_ROOT "${EXTERNAL_PACKAGE_ROOT}/gmock-1.7.0")
set (SFML_ROOT "${EXTERNAL_PACKAGE_ROOT}/sfml-2.1")

if (LIB64)
  set (LIB_SUFFIX "64")
else()
  set (LIB_SUFFIX "")
endif()

set (BUILD_DIR ".")
set (INSTALL_LIB_DIR "lib${LIB_SUFFIX}")
set (HEADER_DIR "include")
set (SOURCE_DIR "src")
set (TEST_DIR "test")

list (APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")
list (APPEND CMAKE_MODULE_PATH "${SFML_ROOT}/cmake/Modules") 

project (${PROJECT_NAME})
enable_testing ()

# Set the default type of build when using a single-configuration generator like the Makefile generator.
if (CMAKE_BUILD_TYPE STREQUAL "")
  set (CMAKE_BUILD_TYPE Release)
endif()

if (CMAKE_COMPILER_IS_GNUCXX)
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS GNUCXX_MINIMUM_VERSION)
    message (FATAL_ERROR "GCC version must be at least ${GNUCXX_MINIMUM_VERSION}!")
  endif()
else()
  message (FATAL_ERROR "Invalid compiler!")
endif()

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=${CXX_STANDARD} ${GNUCXX_FLAGS}")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR})

file (GLOB HEADER_FILES "${HEADER_DIR}/*.h")
file (GLOB SOURCE_FILES "${SOURCE_DIR}/*.cc")

include_directories (${HEADER_DIR})
set (EXECUTABLE_PATH "${BUILD_DIR}/${PROJECT_NAME}")
add_executable (${EXECUTABLE_PATH} ${SOURCE_FILES})
install (TARGETS ${EXECUTABLE_PATH} DESTINATION ${PROJECT_NAME})

# Find "Simple and Fast Multimedia Library (SFML)".
set (SFML_STATIC_LIBRARIES TRUE)
find_package (SFML 2.1 COMPONENTS audio graphics window system REQUIRED)
include_directories (SYSTEM ${SFML_INCLUDE_DIR})
target_link_libraries (${EXECUTABLE_PATH} ${SFML_LIBRARIES})

# Find thread library.
find_package (Threads REQUIRED)

# Find "Google Test (GTest)".
find_package (GTest 1.7.0 REQUIRED)
include_directories (SYSTEM ${GTEST_INCLUDE_DIRS})

# Find "Google Mock (GMock)".
find_package (GMock 1.7.0 REQUIRED)
include_directories (SYSTEM ${GMOCK_INCLUDE_DIRS})

file (GLOB TEST_FILES "${TEST_DIR}/*.cc")

foreach (TEST_FILE ${TEST_FILES})
  get_filename_component (TEST_NAME ${TEST_FILE} NAME_WE)
  set (TEST_EXECUTABLE "${BUILD_DIR}/${TEST_NAME}")
  add_executable (${TEST_EXECUTABLE} ${TEST_FILE})
  target_link_libraries (${TEST_EXECUTABLE} ${PROJECT_NAME}_static ${CMAKE_THREAD_LIBS_INIT} ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} ${GMOCK_LIBRARIES} ${GMOCK_MAIN_LIBRARIES})
  add_test (NAME ${TEST_NAME} COMMAND ${TEST_EXECUTABLE})
endforeach()

set (CPACK_GENERATOR "ZIP")

include (CPack)
