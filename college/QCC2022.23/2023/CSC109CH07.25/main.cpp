#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

#include "ItemToPurchase.h"

int main()
{
    // a lot of this should honestly probably part of the class...
    cout << "Item 1\nEnter the item name:\n";
    string in;
    getline(cin, in);
    cout << "Enter the item price:\n";
    int ip;
    cin >> ip;
    cin.ignore();
    cout << "Enter the item quantity:\n";
    int iq;
    cin >> iq;
    cin.ignore();
    ItemToPurchase i1;
    i1.SetName(in);
    i1.SetQuantity(iq);
    i1.SetPrice(ip);

    cout << "\nItem 2\nEnter the item name:\n";
    getline(cin, in);
    cout << "Enter the item price:\n";
    cin >> ip;
    cin.ignore();
    cout << "Enter the item quantity:\n";
    cin >> iq;
    cin.ignore();
    ItemToPurchase i2;
    i2.SetName(in);
    i2.SetQuantity(iq);
    i2.SetPrice(ip);

    cout << "\nTOTAL COST\n";
    cout << i1.GetName() << ' ' << i1.GetQuantity() << " @ $" << i1.GetPrice() << " = $" << i1.GetPrice() * i1.GetQuantity() << endl;
    cout << i2.GetName() << ' ' << i2.GetQuantity() << " @ $" << i2.GetPrice() << " = $" << i2.GetPrice() * i2.GetQuantity() << endl;
    cout << "\nTotal: $" << (i1.GetPrice() * i1.GetQuantity()) + (i2.GetPrice() * i2.GetQuantity()) << endl;
    return 0;
}
