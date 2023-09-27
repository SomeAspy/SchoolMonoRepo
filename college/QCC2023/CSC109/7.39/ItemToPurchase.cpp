// Copyright 2023
#include <iostream>
#include <string>
#include "ItemToPurchase.h"

using std::cout;
using std::string;

ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
    itemDescription = "none";
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

void ItemToPurchase::SetDescription(string itemDescription)
{
    this->itemDescription = itemDescription;
}

void ItemToPurchase::SetPrice(int itemPrice)
{
    this->itemPrice = itemPrice;
}

void ItemToPurchase::SetQuantity(int itemQuantity)
{
    this->itemQuantity = itemQuantity;
}

string ItemToPurchase::GetName() const
{
    return itemName;
}

string ItemToPurchase::GetDescription() const
{
    return itemDescription;
}

int ItemToPurchase::GetPrice() const
{
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const
{
    return itemQuantity;
}

int ItemToPurchase::GetTotal() const
{
    return itemPrice * itemQuantity;
}

void ItemToPurchase::PrintItemCost() const
{
    cout << itemName << ' ' << itemQuantity << " @ $" << itemPrice << " = $" << GetTotal() << '\n';
}

void ItemToPurchase::PrintItemDescription() const
{
    cout << itemName << ": " << itemDescription << '\n';
}