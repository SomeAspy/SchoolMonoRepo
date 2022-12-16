// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <iostream>
using namespace std;
int main()
{
    char grade;
    cin >> grade;
    switch (grade)
    {
    case 'A':
        cout << "89-100";
        break;
    case 'B':
        cout << "79-88";
        break;
    case 'C':
        cout << "69-78";
        break;
    case 'D':
        cout << "59-68";
        break;
    default:
        cout << "0-58";
    }
    return 0;
}
