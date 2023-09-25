// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "ItemToPurchase.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestEverything()
    {
        ItemToPurchase x;
        x.SetName("xyz");
        x.SetPrice(12);
        x.SetQuantity(10);
        TS_ASSERT_EQUALS(x.GetName(), "xyz");
        TS_ASSERT_EQUALS(x.GetPrice(), 12);
        TS_ASSERT_EQUALS(x.GetQuantity(), 10);
        TS_ASSERT_EQUALS(x.GetTotal(), 120);
        x.PrintItem();
    }
};
#endif /* NEWCXXTEST_H */
