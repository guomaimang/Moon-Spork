cmake_minimum_required(VERSION 3.17)
project(Programs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Programs
        main.cpp course.h search.cpp input.cpp dictionary.h DisplayResult.cpp ReadData.cpp LoadDictionary.cpp )
