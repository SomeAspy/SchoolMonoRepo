// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
#include "MileageTrackerNode.h"
// Include your classes header file(s) below and uncomment.

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestStructors()
    {
        MileageTrackerNode *x = new MileageTrackerNode();
        MileageTrackerNode *y = new MileageTrackerNode(10, "x");
        MileageTrackerNode *z = new MileageTrackerNode(10, "x", y);

        delete x, y, z;
    }
    void TestPrint()
    {
        MileageTrackerNode *x = new MileageTrackerNode();
        x->PrintNodeData();
        delete x;
    }
    void TestBuilders()
    {
        MileageTrackerNode *x = new MileageTrackerNode();
        MileageTrackerNode *y = new MileageTrackerNode(10, "x");

        x->InsertAfter(y);

        TS_ASSERT_EQUALS(x->GetNext(), y);
        delete x;
    }
    void TestGetters()
    {
        MileageTrackerNode *x = new MileageTrackerNode();

        TS_ASSERT_EQUALS(x->GetDate(), "");
        TS_ASSERT_DELTA(x->GetMiles(), 0.0, .01);
    }
};
#endif /* NEWCXXTEST_H */
