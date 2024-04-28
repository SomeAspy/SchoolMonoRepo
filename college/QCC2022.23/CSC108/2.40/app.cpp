// Copyright (c) 2022 Aiden
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y, z;

    cin >> x >> y >> z;

    cout << pow(x, z) << " " << pow(x, pow(y, z)) << " " << abs(y) << " " << sqrt(pow(x * y, z)) << endl;

    return 0;
}