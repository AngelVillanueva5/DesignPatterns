cmake_minimum_required(VERSION 3.22.1)
PROJECT(design VERSION 0.1.0)
#target_include_directories(design include/)

include_directories(include)
set(SOURCES
    src/main.cpp
    src/FileRead.cpp
)
# Add the executable
add_executable(design ${SOURCES})
