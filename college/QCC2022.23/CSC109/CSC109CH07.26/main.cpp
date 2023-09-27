// Copyright 2023
#include <iostream>
#include <string>
#include <ostream>

using namespace std;

#include "ShoppingCart.h"

// This is the third rewrite, I want to fucking kill myself.
// This is the fourth rewrite, I am going to blow a fucking gasket.

void PrintMenu()
{
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
}

void ExecuteMenu(char c, ShoppingCart *cart)
{
    int price, quantity;
    string name, desc;
    switch (c)
    {
    case 'q':
        exit(0);
    case 'o':
        cout << "OUTPUT SHOPPING CART" << endl;
        cart->PrintTotal();
        break;
    case 'i':
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        cart->PrintDescriptions();
        break;
    case 'a':
        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter the item name:" << endl;
        cin.ignore();
        getline(cin, name);
        cout << "Enter the item description:" << endl;
        getline(cin, desc);
        cout << "Enter the item price:" << endl;
        cin >> price;
        cout << "Enter the item quantity:" << endl
             << endl; // plskillme
        cin >> quantity;
        cart->AddItem(ItemToPurchase(name, desc, price, quantity));
        break;
    case 'd':
        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove:" << endl;
        cin.ignore();
        getline(cin, name);
        cart->RemoveItem(name);
        cout << endl;
        break;
    case 'c':
        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name:" << endl;
        cin.ignore();
        getline(cin, name);
        cout << "Enter the new quantity:" << endl;
        cin >> quantity;
        for (unsigned int i = 0; i < cart->GetCartItems().size(); ++i)
        {
            if (cart->GetCartItems().at(i).GetName() == name)
            {
                desc = cart->GetCartItems().at(i).GetDescription();
                price = cart->GetCartItems().at(i).GetPrice();
            }
            cart->ModifyItem(ItemToPurchase(name, desc, price, quantity));
            break;
        }
    }
}

void ExecuteMenu(char c, ShoppingCart cart)
{
    // GO FUCK YOURSELF ZYBOOKS
    ExecuteMenu(c, &cart);
}

int main()
{
    string cName;
    string cDate;

    cout << "Enter customer's name:" << endl;
    getline(cin, cName);
    cout << "Enter today's date:" << endl;
    getline(cin, cDate);

    cout << endl
         << "Customer name: " << cName << endl;
    cout << "Today's date: " << cDate << endl
         << endl;
    ShoppingCart *cart = new ShoppingCart(cName, cDate);
    while (true)
    {
        // cout << endl;
        PrintMenu();
        char validMenuOptions[] = {'a', 'd', 'c', 'i', 'o', 'q'};
        bool invalid = true;
        cout << endl;
        char c;

        while (invalid)
        {
            cout << "Choose an option:" << endl;
            invalid = false;
            cin >> c;
            for (int i = 0; i < 6; i++)
            {
                if (c == validMenuOptions[i])
                {
                    invalid = false;
                    break;
                }
                else
                {
                    invalid = true;
                }
            }
        }
        ExecuteMenu(c, cart);
    }
}
