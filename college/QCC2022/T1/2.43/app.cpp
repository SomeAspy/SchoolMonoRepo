// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double caffeineMg;

    cin >> caffeineMg;

    cout << "After 6 hours: " << fixed << setprecision(2) << caffeineMg * 0.5 << " mg\nAfter 12 hours: " << caffeineMg * 0.25 << " mg\nAfter 24 hours: " << caffeineMg * 0.0625 << " mg\n";
    return 0;
}
