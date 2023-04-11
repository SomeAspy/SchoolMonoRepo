// Copyright 2023
#include <string>
#include <iostream>
#include "ShoppingCart.h"

using std::cout;
using std::string;

ShoppingCart::ShoppingCart()
{
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string customerName, string currentDate)
{
    this->customerName = customerName;
    this->currentDate = currentDate;
}

string ShoppingCart::GetCustomerName()
{
    return customerName;
}

string ShoppingCart::GetDate()
{
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item)
{
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name)
{
    for (unsigned int i = 0; i < cartItems.size(); ++i)
    {
        if (cartItems.at(i).GetName() == name)
        {
            cartItems.erase(cartItems.begin() + i);
            return;
        }
    }
    cout << "Item not found in cart. Nothing removed.\n";
}

void ShoppingCart::ModifyItem(ItemToPurchase item)
{
    for (unsigned int i = 0; i < cartItems.size(); ++i)
    {
        if (cartItems[i].GetName() == item.GetName())
        {
            cartItems[i] = item;
            return;
        }
    }
    cout << "Item not found in cart. Nothing modified.\n\n";
}

int ShoppingCart::GetNumItemsInCart()
{
    unsigned int numItems = 0;
    for (unsigned int i = 0; i < cartItems.size(); ++i)
    {
        numItems += cartItems[i].GetQuantity();
    }
    return numItems;
}

int ShoppingCart::GetCostOfCart()
{
    int cost = 0;
    for (unsigned int i = 0; i < cartItems.size(); ++i)
    {
        cost += cartItems[i].GetPrice() * cartItems[i].GetQuantity();
    }
    return cost;
}

void ShoppingCart::PrintHeader()
{
    cout << customerName << "'s Shopping Cart - " << currentDate << "\n";
}

void ShoppingCart::PrintTotal()
{
    PrintHeader();
    cout << "Number of Items: " << GetNumItemsInCart() << '\n';

    if (!cartItems.size())
    {
        cout << "\nSHOPPING CART IS EMPTY\n\nTotal: $0\n\n";
        return;
    }
    cout << '\n'; // why just why
    for (unsigned int i = 0; i < cartItems.size(); ++i)
    {
        cartItems[i].PrintItemCost();
    }
    cout << "\nTotal: $" << GetCostOfCart() << "\n\n";
}

void ShoppingCart::PrintDescriptions()
{
    PrintHeader();
    cout << '\n'; // why just why
    cout << "Item Descriptions\n";
    for (unsigned int i = 0; i < cartItems.size(); ++i)
    {
        cartItems[i].PrintItemDescription();
    }
    cout << '\n';
}

vector<ItemToPurchase> ShoppingCart::GetCartItems()
{
    return cartItems;
}
