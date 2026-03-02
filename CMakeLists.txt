cmake_minimum_required(VERSION 4.0)
project(project)

set(CMAKE_CXX_STANDARD 20)

add_executable(project main.cpp
        student.h
        course.h
        storage.h
        utils.h
        student.cpp
        Storage.cpp
        course.cpp
        utlis.cpp)
