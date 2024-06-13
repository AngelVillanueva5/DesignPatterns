cmake_minimum_required(VERSION 3.22.1)
PROJECT(design VERSION 0.1.0)
#target_include_directories(design include/)

include_directories(include)
set(SOURCES
    src/main.cpp
    src/FileRead.cpp
    src/component.cpp
    src/and.cpp
    src/composite.cpp
    src/input.cpp
    src/iterator.cpp
    src/not.cpp
    src/or.cpp
    src/probe.cpp
    src/xor.cpp
)
# Add the executable
add_executable(design ${SOURCES})
