// Copyright 2023
#if !defined(MACRO)
#define CSC109CH0725_SHOPPINGCART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"

using std::string;
using std::vector;

class ShoppingCart
{

public:
    ShoppingCart();
    ShoppingCart(string customerName, string currentDate);
    string GetCustomerName();
    string GetDate();
    void AddItem(ItemToPurchase item);
    void RemoveItem(string name);
    void ModifyItem(ItemToPurchase item);
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintHeader();
    void PrintTotal();
    void PrintDescriptions();
    vector<ItemToPurchase> GetCartItems(); // There is no rule against adding more functions

private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};
#endif // CSC109CH0725_SHOPPINGCART_H
