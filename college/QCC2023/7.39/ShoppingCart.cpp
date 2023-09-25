// Copyright 2023
#include "ShoppingCart.h"
#include <string>
#include <iostream>

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

string ShoppingCart::GetCustomerName() const
{
    return customerName;
}

string ShoppingCart::GetDate() const
{
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item)
{
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string itemName)
{
    bool found = false;
    for (unsigned int i = 0; i < cartItems.size(); ++i)
    {
        if (cartItems.at(i).GetName() == itemName)
        {
            cartItems.erase(cartItems.begin() + i);
            found = true;
        }
    }
    if (!found)
    {
        cout << "Item not found in cart. Nothing removed.\n";
    }
}

void ShoppingCart::ModifyItem(ItemToPurchase item)
{
    bool found = false;
    for (unsigned int i = 0; i < cartItems.size(); ++i)
    {
        if (cartItems.at(i).GetName() == item.GetName())
        {
            if (!(item.GetDescription() == "none" || item.GetPrice() == 0 || item.GetQuantity() == 0))
            {
                cartItems.at(i).SetDescription(item.GetDescription());
                cartItems.at(i).SetQuantity(item.GetQuantity());
                cartItems.at(i).SetPrice(item.GetPrice());
            }
            found = true;
        }
    }
    if (!found)
    {
        cout << "Item not found in cart. Nothing modified.\n";
    }
}

int ShoppingCart::GetNumItemsInCart() const
{
    return cartItems.size();
}

int ShoppingCart::GetCostOfCart() const
{
    int total = 0;
    for (unsigned int i = 0; i < cartItems.size(); ++i)
    {
        total += cartItems.at(i).GetTotal();
    }
    return total;
}

void ShoppingCart::PrintTotal() const
{
    // if (cartItems.size() != 0)
    //{
    cout << customerName << "'s Shopping Cart - " << currentDate << "\nNumber of Items: " << GetNumItemsInCart() << "\n\n";
    for (unsigned int i = 0; i < cartItems.size(); ++i)
    {
        cartItems.at(i).PrintItemCost();
    }
    // if (!skipTotal)
    // {
    //     cout << "\nTotal: $" << GetCostOfCart() << '\n';
    // }
    // }
    // else
    // {
    //     cout << "SHOPPING CART IS EMPTY\n";
    // }
}

void ShoppingCart::PrintDescriptions() const
{
    if (cartItems.size() != 0)
    {
        // if (!skipHeader)
        // {
        //     cout << customerName << "'s Shopping Cart - " << currentDate << "\n\nItem Descriptions\n";
        // }
        for (unsigned int i = 0; i < cartItems.size(); ++i)
        {
            cartItems.at(i).PrintItemCost();
        }
    }
    else
    {
        cout << "SHOPPING CART IS EMPTY\n";
    }
}