// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "Car.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestGetSet()
    {
        Car x;
        x.SetModelYear(9999);
        TS_ASSERT_EQUALS(9999, x.GetModelYear());
        x.SetPurchasePrice(5);
        TS_ASSERT_EQUALS(5, x.GetPurchasePrice());
    }

    void TestCalc()
    {
        Car x;
        x.SetModelYear(2021);
        x.SetPurchasePrice(20000);
        x.CalcCurrentValue(2023);
        TS_ASSERT_DELTA(x.GetCurrentValue(), 14450, 1)
        x.PrintInfo();
    }
};
#endif /* NEWCXXTEST_H */
