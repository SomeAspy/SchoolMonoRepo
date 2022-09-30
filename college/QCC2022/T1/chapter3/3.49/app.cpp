// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string firstName, middleName, lastName;
    cin >> firstName >> middleName >> lastName;

    if (lastName.length() != 0)
    {
        cout << lastName << ", " << firstName[0] << '.' << middleName[0] << ".\n";
    }
    else
    {
        cout << middleName << ", " << firstName[0] << ".\n";
    }

    return 0;
}