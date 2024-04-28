// Copyright (c) 2022 Aiden
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name, location, noun;
    int number;

    cin >> name >> location >> number >> noun;

    cout << name << " went to " << location << " to buy " << number << " different types of " << noun << "." << endl;
    return 0;
}