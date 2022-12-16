// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int total = 0, quarters, dimes, nickels, pennies;

    cin >> quarters >> dimes >> nickels >> pennies;

    total += quarters * 25;
    total += dimes * 10;
    total += nickels * 5;
    total += pennies * 1;

    cout << "Amount: $" << fixed << setprecision(2) << total / 100.0 << endl;

    return 0;
}