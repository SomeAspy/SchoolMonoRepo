// Copyright (c) 2022 Aiden
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>

using namespace std;

int main()
{
    int year;
    cin >> year;

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                cout << year << " - leap year" << endl;
            }
            else
            {
                cout << year << " - not a leap year" << endl;
            }
        }
        else
        {
            cout << year << " - leap year" << endl;
        }
    }
    else
    {
        cout << year << " - not a leap year" << endl;
    }

    return 0;
}