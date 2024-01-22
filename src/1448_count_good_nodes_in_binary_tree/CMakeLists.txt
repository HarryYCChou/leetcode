# Minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Project name
project(1448_count_good_nodes_in_binary_tree)

# Define the source files
set(SOURCE_MAIN main.cc)

# Build executable
add_executable(${PROJECT_NAME} ${SOURCE_MAIN})
