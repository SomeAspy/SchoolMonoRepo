// Copyright 2023
#include <iostream>
#include <string>
#include "ShoppingCart.h"

using std::cin;
using std::cout;
using std::getline;
using std::string;

// ZyBooks is something else - Required by ZyBooks
using std::endl;
using std::ostringstream;
using std::streambuf;

void PrintMenu(ShoppingCart cart)
{
    bool inMenu = true;
    char choice;
    while (inMenu)
    {
        cout << "\nMENU\na - Add item to cart\nd - Remove item from cart\nc - Change item quantity\ni - Output items' descriptions\no - Output shopping cart\nq - Quit\n";
        choice = 'x';
        bool validChoice = false;
        while (!validChoice)
        {
            cout << "\nChoose an option:";
            cin >> choice;
            // This is awful, but it works
            if (choice == 'a' || choice == 'd' || choice == 'c' || choice == 'i' || choice == 'o' || choice == 'q')
            {
                validChoice = true;
            }
        }
        cout << '\n';
        switch (choice)
        {
        case 'a':
            // a
            break;
        case 'd':
            // d
            break;
        case 'c':
            // c
            break;
        case 'i':
            // i
            break;
        case 'o':
            cout << "OUTPUT SHOPPING CART\n";
            cart.PrintTotal();
            cout << '\n';
            cart.PrintDescriptions();
            cout << "\nTotal: $" << cart.GetCostOfCart() << '\n';
            break;
        case 'q':
            inMenu = false;
        }
    }
}

int main()
{
    string name, date;
    cout << "Enter customer's name:\n";
    getline(cin, name);
    cout << "Enter today's date:\n";
    getline(cin, date);
    cout << "\nCustomer name: " << name << "\nToday's date: " << date << '\n';
    ShoppingCart cart = ShoppingCart(name, date);
    PrintMenu(cart);
}