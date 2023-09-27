// Copyright 2023
#if !defined(CSC109CH0725_ITEMTOPURCHASE_H)
#define CSC109CH0725_ITEMTOPURCHASE_H

#include <string>
using std::string;
class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(string itemName, string itemDescription, int itemPrice, int itemQuantity);
    void SetName(string itemName);
    string GetName();
    void SetPrice(int itemPrice);
    int GetPrice();
    void SetQuantity(int itemQuantity);
    int GetQuantity();
    void SetDescription(string itemDescription);
    void PrintItemCost();
    void PrintItemDescription();
    string GetDescription();

private:
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
};
#endif // CSC109CH0725_ITEMTOPURCHASE_H
