# Minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Project name
project(0973_k_closest_points_to_orgin)

# Define the source files
set(SOURCE_MAIN main.cc)

# Build executable
add_executable(${PROJECT_NAME} ${SOURCE_MAIN})
