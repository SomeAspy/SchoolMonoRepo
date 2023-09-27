// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "TimerHrMin.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestEverything()
    {
        TimerHrMin x1(9, 30), x2(13, 5), x3, y1(9, 5), y2(13, 30), y3, z1(9, 30), z2(13, 30), z3;

        if (x2 >= x1)
        {
            x3 = x2 - x1;
        }
        else
        {
            x3 = x1 - x2;
        }

        x1.Print(true);
        x2.Print(true);
        x3.Print(false);
        TS_ASSERT_EQUALS(x3.GetHour(), 3);
        TS_ASSERT_EQUALS(x3.GetMinute(), 35);

        y3 = y2 - y1;

        y1.Print(true);
        y2.Print(true);
        y3.Print(false);
        TS_ASSERT_EQUALS(y3.GetHour(), 4);
        TS_ASSERT_EQUALS(y3.GetMinute(), 25);

        z3 = z2 - z1;

        z1.Print(true);
        z2.Print(true);
        z3.Print(false);
        TS_ASSERT_EQUALS(z3.GetHour(), 4);
        TS_ASSERT_EQUALS(z3.GetMinute(), 0);
    }
};
#endif /* NEWCXXTEST_H */
