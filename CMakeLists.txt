cmake_minimum_required(VERSION 3.21)
project(Hash-Cracker)

set(CMAKE_CXX_STANDARD 20)

add_executable(proj main.cpp md5/md5.cpp md5/md5.h)
