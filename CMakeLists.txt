cmake_minimum_required(VERSION 3.21)
project(DSA_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DSA_Project
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Map.cpp
        Map.h
        MapIterator.cpp
        MapIterator.h
        ShortTest.cpp
        ShortTest.h)
