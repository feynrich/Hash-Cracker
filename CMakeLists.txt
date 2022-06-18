cmake_minimum_required(VERSION 3.0)
project(Hash-Cracker)
set(CMAKE_CXX_STANDARD 20)


enable_testing()
add_subdirectory(external)

set(source_cpp src/md5.cpp src/gen.cpp src/sha.cpp )

add_executable(test_hash_cracker src/tests.cpp ${source_cpp})
target_link_libraries(test_hash_cracker PUBLIC doctest)


add_executable(proj src/main.cpp ${source_cpp})

