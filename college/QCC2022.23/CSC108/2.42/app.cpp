// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    long double a, b, c, d, product, avg;

    cin >> a >> b >> c >> d;

    // this is fucking stupid
    int aOF = a, bOF = b, cOF = c, dOF = d, productOF;

    productOF = aOF * bOF * cOF * dOF;

    product = a * b * c * d;
    avg = (a + b + c + d) / 4;

    cout << fixed << setprecision(0) << productOF << " " << static_cast<int>(avg) << endl;
    cout << fixed << setprecision(3) << product << " " << avg << endl;
    return 0;
}