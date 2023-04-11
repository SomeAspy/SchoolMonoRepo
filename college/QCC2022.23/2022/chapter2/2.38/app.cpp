// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double mpg, cost, pricePerMile;

    cin >> mpg >> cost;

    pricePerMile = cost / mpg;

    cout << fixed << setprecision(2) << pricePerMile * 20 << " " << pricePerMile * 75 << " " << pricePerMile * 500 << endl;
    return 0;
}