# Minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Project name
project(1584_min_cost_to_connect_all_points)

# Define the source files
set(SOURCE_MAIN main.cc)

# Build executable
add_executable(${PROJECT_NAME} ${SOURCE_MAIN})
