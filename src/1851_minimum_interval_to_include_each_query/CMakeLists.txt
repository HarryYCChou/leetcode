# Minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Project name
project(1851_minimum_interval_to_include_each_query)

# Define the source files
set(SOURCE_MAIN main.cc)

# Build executable
add_executable(${PROJECT_NAME} ${SOURCE_MAIN})
