project(fizz-buzz-whizz)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE all_files
    src/*.cpp
    src/*.cxx
    src/*.cc
    src/*.c
    src/*.C
    test/*.cpp
    test/*.cxx
    test/*.cc
    test/*.c
    test/*.C)

add_executable(fizz-buzz-whizz-test ${all_files})
target_link_libraries(fizz-buzz-whizz-test cut)

