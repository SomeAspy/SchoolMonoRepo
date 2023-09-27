cmake_minimum_required(VERSION 3.23)
project(CSC109CH06_72)

set(CMAKE_CXX_STANDARD 14)

set(CXXTEST_INCLUDE_DIR c:/users/aiden/documents/cpp/cxxtest)

set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE c:/users/aiden/documents/cpp/cxxtest/bin/cxxtestgen)

find_package(CxxTest REQUIRED)


if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    CXXTEST_ADD_TEST(Test.h
        runner.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TwoDArray.cpp  # add source files
        ${CMAKE_CURRENT_SOURCE_DIR}/Tests.h
        )

endif()

add_executable(CSC109CH06_72 runner.cpp TwoDArray.cpp TwoDArray.h)