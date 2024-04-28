// Copyright (c) 2022 Aiden
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>

using namespace std;

int main()
{
    int centsIn, dollars, quarters, dimes, nickels, pennies;
    cin >> centsIn;
    if (centsIn != 0)
    {
        cin >> centsIn;
        dollars = centsIn / 100;
        centsIn %= 100;
        quarters = centsIn / 25;
        centsIn %= 25;
        dimes = centsIn / 10;
        centsIn %= 10;
        nickels = centsIn / 5;
        centsIn %= 5;
        pennies = centsIn;

        if (dollars > 1 && dollars != 0)
        {
            cout << dollars << " Dollars" << endl;
        }
        else if (dollars == 1)
        {
            cout << dollars << " Dollar" << endl;
        }

        if (quarters > 1 && quarters != 0)
        {
            cout << quarters << " Quarters" << endl;
        }
        else if (quarters == 1)
        {
            cout << quarters << " Quarter" << endl;
        }

        if (dimes > 1 && dimes != 0)
        {
            cout << dimes << " Dimes" << endl;
        }
        else if (dimes == 1)
        {
            cout << dimes << " Dime" << endl;
        }

        if (nickels > 1 && nickels != 0)
        {
            cout << nickels << " Nickels" << endl;
        }
        else if (nickels == 1)
        {
            cout << nickels << " Nickel" << endl;
        }

        if (pennies > 1 && pennies != 0)
        {
            cout << pennies << " Pennies" << endl;
        }
        else if (pennies == 1)
        {
            cout << pennies << " Penny" << endl;
        }
    }
    else
    {
        cout << "No change" << endl;
    }

    return 0;
}