// Copyright (c) 2022 Aiden
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;

    cout << "Please enter the first integer: ";
    cin >> a;
    cout << "Please enter the second integer: ";
    cin >> b;

    cout << "The sum of " << a << " and " << b << " is " << (a + b) << ".\n";

    cout << "The difference of " << a << " and " << b << " is " << (a - b) << ".\n";

    cout << "The product of " << a << " and " << b << " is " << (a * b) << ".\n";

    cout << "The average of " << a << " and " << b << " is " << (((a + b) * 1.0) / 2) << ".\n";

    cout << "The distance between " << a << " and " << b << " is " << abs(a - b) << ".\n";

    cout << "The maximum of " << a << " and " << b << " is " << max(a, b) << ".\n";

    cout << "The minimum of " << a << " and " << b << " is " << min(a, b) << ".\n";

    return 0;
}
