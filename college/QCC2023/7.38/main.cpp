// Copyright 2023
#include <iostream>
#include <string>
#include "ItemToPurchase.h"

using std::cin;
using std::cout;
using std::endl; // ZyBooks is something else
using std::getline;
using std::string;

int main()
{

    string item;
    int count, price;
    ItemToPurchase x, y;

    cout << "Item 1\nEnter the item name:\n";
    getline(cin, item);
    cout << "Enter the item price:\n";
    cin >> price;
    cout << "Enter the item quantity:\n";
    cin >> count;
    cin.ignore();

    x.SetName(item);
    x.SetPrice(price);
    x.SetQuantity(count);

    cout << "\nItem 2\nEnter the item name:\n";
    getline(cin, item);
    cout << "Enter the item price:\n";
    cin >> price;
    cout << "Enter the item quantity:\n";
    cin >> count;
    cin.ignore();

    y.SetName(item);
    y.SetPrice(price);
    y.SetQuantity(count);

    cout << "\nTOTAL COST\n";
    x.PrintItem();
    y.PrintItem();
    cout << "\nTotal: $" << x.GetTotal() + y.GetTotal() << '\n';

    return 0;
}
