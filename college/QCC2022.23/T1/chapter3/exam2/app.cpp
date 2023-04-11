// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string firstName, lastName, out;
    int year;
    cin >> firstName >> lastName >> year;
    if (lastName.length() > 5)
    {
        out = lastName.substr(0, 5);
    }
    else
    {
        out = lastName;
    }

    out += firstName[0];
    out += to_string(year % 100);
    cout << "Your login name: " << out << endl;
    return 0;
}