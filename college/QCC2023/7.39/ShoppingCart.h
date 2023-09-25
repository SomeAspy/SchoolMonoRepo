// Copyright 2023
#include "ItemToPurchase.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class ShoppingCart
{
public:
    ShoppingCart();
    ShoppingCart(string customerName, string currentDate);
    string GetCustomerName() const;
    string GetDate() const;
    void AddItem(ItemToPurchase item);
    void RemoveItem(string itemName);
    void ModifyItem(ItemToPurchase item);
    int GetNumItemsInCart() const;
    int GetCostOfCart() const;
    void PrintTotal() const;
    void PrintDescriptions() const;

private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};