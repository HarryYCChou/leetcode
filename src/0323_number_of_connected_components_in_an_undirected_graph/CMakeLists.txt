# Minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Project name
project(0323_number_of_connected_components_in_an_undirected_graph)

# Define the source files
set(SOURCE_MAIN main.cc)

# Build executable
add_executable(${PROJECT_NAME} ${SOURCE_MAIN})
