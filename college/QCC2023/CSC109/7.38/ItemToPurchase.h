// Copyright 2023
#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using std::string;

class ItemToPurchase
{
public:
    ItemToPurchase();
    void SetName(string itemName);
    void SetPrice(int itemPrice);
    void SetQuantity(int itemQuantity);
    string GetName() const;
    int GetPrice() const;
    int GetQuantity() const;
    void PrintItem() const;
    int GetTotal() const;

private:
    string itemName;
    int itemPrice;
    int itemQuantity;
};

#endif
