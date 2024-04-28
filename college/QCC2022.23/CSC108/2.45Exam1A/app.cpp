// Copyright (c) 2022 Aiden
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float keyUp(float key, float keyUp)
{
    key *= pow(pow(2, 1.0 / 12.0), keyUp);
    return key;
}

int main()
{
    float key;
    cin >> key;

    cout << fixed << setprecision(2) << key << ' ' << keyUp(key, 1) << ' ' << keyUp(key, 2) << ' ' << keyUp(key, 3) << ' ' << keyUp(key, 4) << endl;

    return 0;
}