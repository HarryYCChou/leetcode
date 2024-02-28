# Minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Project name
project(1899_merge_triplets_to_form_target_triplet)

# Define the source files
set(SOURCE_MAIN main.cc)

# Build executable
add_executable(${PROJECT_NAME} ${SOURCE_MAIN})
