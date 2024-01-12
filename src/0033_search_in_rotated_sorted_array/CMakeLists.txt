# Minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Project name
project(0033_search_in_rotated_sorted_array)

# Define the source files
set(SOURCE_MAIN main.cc)

# Build executable
add_executable(${PROJECT_NAME} ${SOURCE_MAIN})
