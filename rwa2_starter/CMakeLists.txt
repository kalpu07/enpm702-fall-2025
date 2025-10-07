cmake_minimum_required(VERSION 3.28)
project(rwa2_starter VERSION 1.0 LANGUAGES C CXX)



include_directories(include)
add_executable(rwa2_starter_cpp src/main.cpp)

# Set C++17 standard for the targets
set_property(TARGET rwa2_starter_cpp PROPERTY CXX_STANDARD 17)
set_property(TARGET rwa2_starter_cpp PROPERTY CXX_STANDARD_REQUIRED ON)