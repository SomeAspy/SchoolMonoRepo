// Copyright (c) 2022 Aiden
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    while (num > 0)
    {
        cout << num % 2;
        num /= 2;
    }
    cout << endl;

    return 0;
}