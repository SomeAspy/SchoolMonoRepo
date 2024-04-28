// Copyright (c) 2022 Aiden
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

// none of this met the criteria for the question for whatever reason...

#include <iostream>

using namespace std;

int main()
{
    double numbers[10], result = 1;
    for (int i = 1; i < 10; i++)
    {
        cin >> numbers[i];
        result *= numbers[i];
    };
    cout << result << endl;
    result = 0;
    for (int i = 1; i < 10; i++)
    {
        cin >> numbers[i];
        result += 1 / numbers[i];
    };
    cout << 1 / result << endl;
    return 0;
}
