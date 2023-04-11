// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <string>
using namespace std;

int main()
{

    cout << "Enter text:\n";
    string text;
    getline(cin, text);
    cout << "You entered: " << text << endl;

    if (text.find("BFF") != -1)
    {
        cout << "BFF: best friend forever\n";
    }
    if (text.find("IDK") != -1)
    {
        cout << "IDK: I don't know\n";
    }
    if (text.find("JK") != -1)
    {
        cout << "JK: just kidding\n";
    }
    if (text.find("TMI") != -1)
    {
        cout << "TMI: too much information\n";
    }
    if (text.find("TTYL") != -1)
    {
        cout << "TTYL: talk to you later\n";
    }
    return 0;
}