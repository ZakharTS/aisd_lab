cmake_minimum_required(VERSION 3.22)
project(task)

set(CMAKE_CXX_STANDARD 14)

add_executable(task main.cpp bstree.h bstree.cpp hashtab.h hashtab.cpp)
