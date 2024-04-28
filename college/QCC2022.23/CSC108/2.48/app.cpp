// Copyright (c) 2022 Aiden
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    float height, width, cost;

    cin >> height >> width >> cost;

    cout << fixed << setprecision(1)
         << "Wall area: " << height * width << setprecision(3) << " sq ft" << endl
         << "Paint needed: " << height * width / 350 << " gallons" << endl
         << "Cans needed: " << setprecision(0) << ceil(height * width / 350) << " can(s)" << endl
         << setprecision(2) << "Paint cost: $" << ceil(height * width / 350) * cost << endl
         << "Sales tax: $" << ceil(height * width / 350) * cost * 0.07 << endl
         << "Total cost: $" << ceil(height * width / 350) * cost * 1.07 << endl;
    return 0;
}