# Minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Project name
project(0000_template)

# Define the source files
set(SOURCE_MAIN main.cc)

# Find the required libraries
#find_package(xxx REQUIRED)

# Subdirectory
#add_subdirectory(lib/xxx)

# Build executable
add_executable(${PROJECT_NAME} ${SOURCE_MAIN})
# Link xxx to the executable
#target_link_libraries(${PROJECT_NAME} PRIVATE lib_xxx)
