// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "ItemNode.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestConstructors()
    {
        ItemNode *x = new ItemNode();
        ItemNode *y = new ItemNode("thing");
        ItemNode *z = new ItemNode("thing2", y);

        TS_ASSERT_EQUALS(z->GetNext(), y);
        TS_ASSERT_EQUALS(z->GetItem(), "thing2");
    }
    void TestInserters()
    {
        ItemNode *y = new ItemNode();
        ItemNode *x = new ItemNode("thing", y);
        ItemNode *h = new ItemNode("head", x);
        ItemNode *z = new ItemNode("z");
        ItemNode *a = new ItemNode("a");
        y->InsertAfter(z);
        z->InsertAtEnd(h, a);

        TS_ASSERT_EQUALS(y->GetNext(), z);
        TS_ASSERT_EQUALS(z->GetNext(), a);
    }

    void TestPrint()
    {
        ItemNode *y = new ItemNode("thing");
        y->PrintNodeData();
    }
};
#endif /* NEWCXXTEST_H */
