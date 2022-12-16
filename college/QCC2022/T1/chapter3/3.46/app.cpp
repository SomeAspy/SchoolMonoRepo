// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

// REWRITE 1

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int indexOf(string str[], string search, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (str[i] == search)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string month;
    int day;
    cin >> month >> day;

    string validMonths[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int validDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (indexOf(validMonths, month, sizeof(validMonths) / sizeof(validMonths[0])) != -1)
    {
        int daysInMonth = validDays[indexOf(validMonths, month, sizeof(validMonths) / sizeof(validMonths[0]))];
        if (day > 0 && day <= daysInMonth)
        {
            if ((month == "April" || month == "May") || (month == "March" && day >= 20) || (month == "June" && day <= 20))
            {
                cout << "Spring" << endl;
            }
            else if ((month == "July" || month == "August") || (month == "June" && day >= 21) || (month == "September" && day <= 22))
            {
                cout << "Summer" << endl;
            }
            else if ((month == "October" || month == "November") || (month == "September" && day >= 23) || (month == "December" && day <= 21))
            {
                cout << "Autumn" << endl;
            }
            else
            {
                cout << "Winter" << endl;
            }
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;
}