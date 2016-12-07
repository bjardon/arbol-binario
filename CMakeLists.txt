cmake_minimum_required(VERSION 3.5)
project(Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c tree.h util.h list.h)
add_executable(Tree ${SOURCE_FILES})