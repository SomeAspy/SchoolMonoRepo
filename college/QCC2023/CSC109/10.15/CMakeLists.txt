cmake_minimum_required(VERSION 3.23)
project(THING)

set(CMAKE_CXX_STANDARD 14)

set(CXXTEST_INCLUDE_DIR /usr/include/cxxtest)

set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE /usr/bin/cxxtestgen)

find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    CXXTEST_ADD_TEST(unittest
            runner.cpp  # THIS IS GENERATED BUT YOU NEED TO ADD IT HERE
            ${CMAKE_CURRENT_SOURCE_DIR}/Course.cpp  # add source files
            ${CMAKE_CURRENT_SOURCE_DIR}/Course.h
            ${CMAKE_CURRENT_SOURCE_DIR}/OfferedCourse.cpp  # add source files
            ${CMAKE_CURRENT_SOURCE_DIR}/OfferedCourse.h
            ${CMAKE_CURRENT_SOURCE_DIR}/test.h  # YOUR TEST DESCRIPTION FILE
            )

endif()

add_executable(THING runner.cpp Course.cpp Course.h OfferedCourse.cpp OfferedCourse.h test.h)