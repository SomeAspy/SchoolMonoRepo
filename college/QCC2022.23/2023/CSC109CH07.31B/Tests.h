// Copyright 2023
#define CSC109CH07_26_TESTS_H
#include "Triangle.h"
#include <cxxtest/TestSuite.h>
#include <sstream>
#include <iostream>

using std::cout;
using std::streambuf;
using std::stringstream;

class newCxxTest : public CxxTest::TestSuite
{

public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestTriangle()
    {
        Triangle t;
        t.SetBase(10);
        t.SetHeight(5);
        t.CalculateArea();
        stringstream ss;
        streambuf *oldCoutStreamBuf = cout.rdbuf(ss.rdbuf());
        t.PrintInfo();
        cout.rdbuf(oldCoutStreamBuf);
        TS_ASSERT_EQUALS(ss.str(), "Base: 10.00\nHeight: 5.00\nArea: 25.00\n");
    }
};
