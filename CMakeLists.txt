# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(algorithms_c C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Enable all compiler warnings
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")

# Debug build with symbols
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")

# List all source files
file(GLOB_RECURSE DS_SOURCES "src/data_structures/*.c")
file(GLOB_RECURSE ALGO_SOURCES "src/algorithms/*.c")

# Include directories
include_directories(include)

# Create library for data structures and algorithms
add_library(ds_algo STATIC ${DS_SOURCES} ${ALGO_SOURCES})

# Add executables for examples
file(GLOB EXAMPLE_SOURCES "examples/*.c")
foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} ds_algo)
endforeach()

# Testing configuration
enable_testing()

# Add tests
file(GLOB TEST_SOURCES "tests/*.c")
foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} ds_algo)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()