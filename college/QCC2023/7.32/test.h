// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "FoodItem.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestGetSet()
    {
        FoodItem x;
        TS_ASSERT_EQUALS(x.GetName(), "Water");
        TS_ASSERT_DELTA(x.GetFat(), 0.0, 1);
        TS_ASSERT_DELTA(x.GetCarbs(), 0.0, 1);
        TS_ASSERT_DELTA(x.GetProtein(), 0.0, 1);

        FoodItem y("xyz", 1.1, 2.2, 3.3);
        TS_ASSERT_EQUALS(y.GetName(), "xyz");
        TS_ASSERT_DELTA(y.GetFat(), 1.1, 1);
        TS_ASSERT_DELTA(y.GetCarbs(), 2.2, 1);
        TS_ASSERT_DELTA(y.GetProtein(), 3.3, 1);
    }
    void TestCalc()
    {
        FoodItem x("xyz", 1.1, 2.2, 3.3);
        TS_ASSERT_EQUALS(x.GetName(), "xyz");
        TS_ASSERT_DELTA(x.GetFat(), 1.1, 1);
        TS_ASSERT_DELTA(x.GetCarbs(), 2.2, 1);
        TS_ASSERT_DELTA(x.GetProtein(), 3.3, 1);
        TS_ASSERT_DELTA(x.GetCalories(3), 95.7, 1);
    }
    void TestPrint()
    {
        FoodItem x("xyz", 1.1, 2.2, 3.3);
        x.PrintInfo();
    }
};
#endif /* NEWCXXTEST_H */
