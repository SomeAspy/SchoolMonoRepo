// Copyright 2023
#define CSC109CH07_26_TESTS_H
#include "ShoppingCart.h"
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

    void TestItemToPurchaseConstructorNull()
    {
        ItemToPurchase test;
        TS_ASSERT_EQUALS(test.GetPrice(), 0);
        TS_ASSERT_EQUALS(test.GetName(), "none");
        TS_ASSERT_EQUALS(test.GetQuantity(), 0);
    }
    void TestItemToPurchaseConstructorParameters()
    {
        ItemToPurchase test("a", "b", 1, 2);
        TS_ASSERT_EQUALS(test.GetPrice(), 1);
        TS_ASSERT_EQUALS(test.GetName(), "a");
        TS_ASSERT_EQUALS(test.GetQuantity(), 2);
        TS_ASSERT_EQUALS(test.GetDescription(), "b");
    }
    void TestItemToPurchaseGettersAndSetters()
    {
        ItemToPurchase test;
        test.SetDescription("a");
        test.SetName("b");
        test.SetPrice(9);
        test.SetQuantity(1);
        TS_ASSERT_EQUALS(test.GetDescription(), "a");
        TS_ASSERT_EQUALS(test.GetName(), "b");
        TS_ASSERT_EQUALS(test.GetPrice(), 9)
        TS_ASSERT_EQUALS(test.GetQuantity(), 1);
    }
    void TestItemToPurchasePrintItemCost()
    {
        ItemToPurchase test;
        test.PrintItemCost();
        // I don't quite understand how this works but it gets the job done
        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        test.PrintItemCost();
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "none 0 @ $0 = $0\n");
    }

    void TestItemToPurchasePrintItemDescription()
    {
        ItemToPurchase test("a", "b", 1, 2);
        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        test.PrintItemDescription();
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "a: b\n");
    }

    void TestShoppingCartConstructorNull()
    {
        ShoppingCart test;
        TS_ASSERT_EQUALS(test.GetDate(), "January 1, 2016");
        TS_ASSERT_EQUALS(test.GetCustomerName(), "none");
    }

    void TestShoppingCartConstructorParameters()
    {
        ShoppingCart test("a", "b");
        TS_ASSERT_EQUALS(test.GetDate(), "b");
        TS_ASSERT_EQUALS(test.GetCustomerName(), "a");
    }

    void TestShoppingCartAddItem()
    {
        ShoppingCart test;
        ItemToPurchase testItem("a", "b", 1, 2);
        test.AddItem(testItem);
        TS_ASSERT_EQUALS(test.GetNumItemsInCart(), 2);
    }

    void TestShoppingCartRemoveItem()
    {
        ShoppingCart test;
        ItemToPurchase testItem("a", "b", 1, 2);
        test.AddItem(testItem);
        test.RemoveItem("a");
        TS_ASSERT_EQUALS(test.GetNumItemsInCart(), 0);
    }

    void TestShoppingCartModifyItemFound()
    {
        ShoppingCart test;
        ItemToPurchase testItem("a", "b", 1, 2), checkItem("a", "d", 3, 4);
        test.AddItem(testItem);
        test.ModifyItem(checkItem);
        TS_ASSERT_EQUALS(test.GetCartItems()[0].GetDescription(), "d");
    }

    void TestShoppingCartModifyItemNotFound()
    {
        ShoppingCart test;
        ItemToPurchase testItem("a", "b", 1, 2);
        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        test.ModifyItem(testItem);
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "Item not found in cart. Nothing modified.\n\n");
    }

    void TestShoppingCartGetCostOfCart()
    {
        ShoppingCart test;
        ItemToPurchase testItem("a", "b", 1, 2), testItem2("a", "d", 3, 4);
        test.AddItem(testItem);
        test.AddItem(testItem2);
        TS_ASSERT_EQUALS(test.GetCostOfCart(), 14);
    }

    void TestShoppingCartPrintTotal()
    {
        ShoppingCart test("a", "b");
        ItemToPurchase testItem("a", "b", 1, 2), testItem2("c", "d", 3, 4);
        test.AddItem(testItem);
        test.AddItem(testItem2);
        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        test.PrintTotal();
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "a\'s Shopping Cart - b\nNumber of Items: 6\n\na 2 @ $1 = $2\nc 4 @ $3 = $12\n\nTotal: $14\n\n");
    }

    void TestShoppingCartEmptyPrintTotal()
    {
        ShoppingCart test("a", "b");
        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        test.PrintTotal();
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "a\'s Shopping Cart - b\nNumber of Items: 0\n\nSHOPPING CART IS EMPTY\n\nTotal: $0\n\n");
    }
    void TestShoppingCartPrintDescriptions()
    {
        ShoppingCart test("a", "b");
        ItemToPurchase testItem("a", "b", 1, 2), testItem2("c", "d", 3, 4);
        test.AddItem(testItem);
        test.AddItem(testItem2);
        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        test.PrintDescriptions();
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "a\'s Shopping Cart - b\n\nItem Descriptions\na: b\nc: d\n\n");
    }

    void TestShoppingCartGetCartItems()
    {
        ShoppingCart test("a", "b");
        ItemToPurchase testItem("a", "b", 1, 2), testItem2("c", "d", 3, 4);
        test.AddItem(testItem);
        test.AddItem(testItem2);
        TS_ASSERT_EQUALS(test.GetCartItems()[0].GetName(), "a");
        TS_ASSERT_EQUALS(test.GetCartItems()[1].GetName(), "c");
    }
    void TestShoppingCartRemoveItemsNoItem()
    {
        ShoppingCart test("a", "b");
        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        test.RemoveItem("a");
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "Item not found in cart. Nothing removed.\n");
    }
};
