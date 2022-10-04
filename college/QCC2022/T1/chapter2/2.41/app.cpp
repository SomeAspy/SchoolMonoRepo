// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
using namespace std;

int main()
{
    long long phone;
    cin >> phone;

    cout << "(" << phone / 10000000 << ") " << (phone % 10000000) / 10000 << "-" << phone % 10000 << endl;
    return 0;
}