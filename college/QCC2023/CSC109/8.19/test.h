// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "InventoryNode.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestConstructors()
    {
        InventoryNode *x = new InventoryNode();
        InventoryNode *y = new InventoryNode("something", 3);
        InventoryNode *z = new InventoryNode("somethingElse", 5, y);

        TS_ASSERT_EQUALS(z->GetNext(), y);
        TS_ASSERT_EQUALS(z->GetItem(), "somethingElse");
        TS_ASSERT_EQUALS(z->GetNumberOfItems(), 5);
    }
    void TestPrint()
    {
        InventoryNode *x = new InventoryNode();
        x->PrintNodeData();
    }
    void TestInsert()
    {

        InventoryNode *x = new InventoryNode();
        InventoryNode *y = new InventoryNode("something", 3);
        InventoryNode *z = new InventoryNode("somethingElse", 5, y);
        InventoryNode *h = new InventoryNode("x", 4, z);
        // order = h,z,y
        x->InsertAtFront(h, x);
        TS_ASSERT_EQUALS(h->GetNext(), x);
        TS_ASSERT_EQUALS(x->GetNext(), z);
    }
};
#endif /* NEWCXXTEST_H */
