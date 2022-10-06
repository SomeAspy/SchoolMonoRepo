// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c, x;
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;
    x = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    if (a * (x * x) + b * x + c == 0)
    {
        cout << "x = " << x << endl;
    }
    else
    {
        cout << "No real roots" << endl;
    }
    return 0;
}