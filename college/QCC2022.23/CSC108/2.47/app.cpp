// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int integer;
    double dbl;
    char character;
    string str;

    cout << "Enter integer:\n";
    cin >> integer;
    cout << "Enter double:\n";
    cin >> dbl;
    cout << "Enter character:\n";
    cin >> character;
    cout << "Enter string:\n";
    cin >> str;

    cout << integer << " " << dbl << " " << character << " " << str << endl
         << str << " " << character << " " << dbl << " " << integer << endl
         << dbl << " cast to an integer is " << static_cast<int>(dbl) << endl;
    return 0;
}