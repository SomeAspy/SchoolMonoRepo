cmake_minimum_required(VERSION 3.23)
project(TEMPLATE)

set(CMAKE_CXX_STANDARD 14)

set(CXXTEST_INCLUDE_DIR c:/Users/aiden/Documents/cpp/cxxtest)

set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE c:/Users/aiden/Documents/cpp/cxxtest/bin/cxxtestgen)

find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    CXXTEST_ADD_TEST(unittest
            runner.cpp  # THIS IS GENERATED BUT YOU NEED TO ADD IT HERE
            ${CMAKE_CURRENT_SOURCE_DIR}/Appointment.cpp  # add source files
            ${CMAKE_CURRENT_SOURCE_DIR}/Daily.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Monthly.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Onetime.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Time.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Date.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Tests.h  # YOUR TEST DESCRIPTION FILE
            )

endif()

add_executable(TEMPLATE runner.cpp Appointment.cpp Appointment.h Daily.cpp Daily.h Monthly.cpp Monthly.h Onetime.cpp Onetime.h Time.cpp Time.h Date.cpp Date.h main.cpp)
