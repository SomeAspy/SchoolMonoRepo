// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "Triangle.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestEverything()
    {
        double base = 99.99;
        Triangle x;

        x.SetBase(5);
        x.SetHeight(10);

        TS_ASSERT_DELTA(x.GetArea(), 25, .01);
    }
    void TestPrint()
    {
        double base = 99.99;
        Triangle x;

        x.SetBase(5);
        x.SetHeight(10);

        x.PrintInfo();
    }
};
#endif /* NEWCXXTEST_H */
