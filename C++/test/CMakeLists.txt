cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        "${PROJECT_SOURCE_DIR}/include"
)

set(CTest
        "${PROJECT_SOURCE_DIR}/include/CTest.h"
        "${PROJECT_SOURCE_DIR}/include/CTest.cpp")

set(Main
        "${PROJECT_SOURCE_DIR}/main.cpp")

add_executable(test
        ${CTest}
        ${Main})
