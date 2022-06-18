cmake_minimum_required(VERSION 3.0)
project(Hash-Cracker)
set(CMAKE_CXX_STANDARD 20)


# Prepare doctest for other targets to us
# Make test executable
enable_testing()

add_library(test_main OBJECT src/md5.cpp src/gen.cpp src/sha.cpp)

add_executable(test1 tests.cpp $<TARGET_OBJECTS:test_main>)
add_test(NAME test1 COMMAND test1)


add_executable(proj src/main.cpp src/gen.h)
