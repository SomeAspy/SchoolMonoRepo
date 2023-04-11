cmake_minimum_required(VERSION 3.23)
project(CSC109CH07.31B)

set(CMAKE_CXX_STANDARD 14)

set(CXXTEST_INCLUDE_DIR c:/Users/aiden/Documents/cpp/cxxtest)

set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE c:/Users/aiden/Documents/cpp/cxxtest/bin/cxxtestgen)

find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    CXXTEST_ADD_TEST(unittest
            runner.cpp  # THIS IS GENERATED BUT YOU NEED TO ADD IT HERE
            ${CMAKE_CURRENT_SOURCE_DIR}/Triangle.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Tests.h  # YOUR TEST DESCRIPTION FILE
            )

endif()

add_executable(CSC109CH07.31B runner.cpp Triangle.cpp Triangle.h Tests.h)
