cmake_minimum_required(VERSION 3.21)
project(Hash_Cracker)

set(CMAKE_CXX_STANDARD 20)

add_executable(Hash_Cracker
        lib/MD5/MD5.cpp)
