#include "ItemToPurchase.h"
#include <string>
using std::string;

ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
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
