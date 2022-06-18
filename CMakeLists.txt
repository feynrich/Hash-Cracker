cmake_minimum_required(VERSION 3.0)
project(Hash-Cracker)
set(CMAKE_CXX_STANDARD 20)


# Prepare doctest for other targets to us
# Make test executable
enable_testing()

add_library(test_main OBJECT src/md5.cpp src/gen.cpp src/sha.cpp)

add_executable(tests_hash_cracker src/tests.cpp $<TARGET_OBJECTS:test_main>)
add_test(NAME test_hash_cracker COMMAND test1)


add_executable(proj src/main.cpp src/gen.h)
