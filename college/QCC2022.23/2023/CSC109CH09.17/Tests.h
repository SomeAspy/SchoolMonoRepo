// Copyright 2023
#define TEMPLATE_TESTS_H
#include <cxxtest/TestSuite.h>

#include "Number.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestNumberConstructor()
    {
        Number num = Number(5);
        TS_ASSERT_EQUALS(num.GetNum(), 5);
    }

    void TestNumberGetSetNum()
    {
        Number num = Number(5);
        num.SetNum(10);
        TS_ASSERT_EQUALS(num.GetNum(), 10);
    }

    void TestNumberOperatorOverload()
    {
        Number num = Number(5);
        cout << num << endl;
        TS_ASSERT_EQUALS(num.GetNum(), 5);
    }
};
