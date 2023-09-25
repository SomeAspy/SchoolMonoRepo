// Copyright 2023
#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using std::string;

class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(string itemName, string itemDescription, int itemPrice, int itemQuantity);
    void SetName(string itemName);
    void SetDescription(string itemDescription);
    void SetPrice(int itemPrice);
    void SetQuantity(int itemQuantity);
    string GetName() const;
    string GetDescription() const;
    int GetPrice() const;
    int GetQuantity() const;
    void PrintItemCost() const;
    void PrintItemDescription() const;
    int GetTotal() const;

private:
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
};

#endif