# Minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Project name
project(0309_best_time_to_buy_and_sell_stock_with_cooldown)

# Define the source files
set(SOURCE_MAIN main.cc)

# Build executable
add_executable(${PROJECT_NAME} ${SOURCE_MAIN})
