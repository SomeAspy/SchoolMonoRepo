// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
using namespace std;

int main()
{
    int baseChar, headChar;
    cin >> baseChar >> headChar;
    cout << "     " << headChar << "\n     " << headChar << headChar << endl
         << baseChar << baseChar << baseChar << baseChar << baseChar << headChar << headChar << headChar << endl
         << baseChar << baseChar << baseChar << baseChar << baseChar << headChar << headChar << headChar << headChar << endl
         << baseChar << baseChar << baseChar << baseChar << baseChar << headChar << headChar << headChar << endl
         << "     " << headChar << headChar << endl
         << "     " << headChar << endl;
}