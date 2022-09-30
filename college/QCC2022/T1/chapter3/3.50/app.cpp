// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Input an abbreviation:\n";
    string abbreviation;
    cin >> abbreviation;
    if (abbreviation == "LOL")
    {
        cout << "laughing out loud" << endl;
    }
    else if (abbreviation == "IDK")
    {
        cout << "I don't know" << endl;
    }
    else if (abbreviation == "BFF")
    {
        cout << "best friends forever" << endl;
    }
    else if (abbreviation == "IMHO")
    {
        cout << "in my humble opinion" << endl;
    }
    else if (abbreviation == "TMI")
    {
        cout << "too much information" << endl;
    }
    else
    {
        cout << "Unknown\n";
    }

    return 0;
}