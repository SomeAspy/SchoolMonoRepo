// Copyright 2023
#include "ItemToPurchase.h"
#include <string>
#include <iostream>

using std::cout;
using std::string;

ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, int itemPrice, int itemQuantity)
{
    this->itemName = itemName;
    this->itemDescription = itemDescription;
    this->itemPrice = itemPrice;
    this->itemQuantity = itemQuantity;
}

void ItemToPurchase::SetName(string itemName)
{
    this->itemName = itemName;
}

string ItemToPurchase::GetName()
{
    return itemName;
}

void ItemToPurchase::SetPrice(int itemPrice)
{
    this->itemPrice = itemPrice;
}

int ItemToPurchase::GetPrice()
{
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int itemQuantity)
{
    this->itemQuantity = itemQuantity;
}

int ItemToPurchase::GetQuantity()
{
    return itemQuantity;
}

void ItemToPurchase::SetDescription(string itemDescription)
{
    this->itemDescription = itemDescription;
}

void ItemToPurchase::PrintItemCost()
{
    cout << itemName << ' ' << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice * itemQuantity << '\n';
}

void ItemToPurchase::PrintItemDescription()
{
    cout << itemName << ": " << itemDescription << '\n';
}

string ItemToPurchase::GetDescription()
{
    return itemDescription;
}
