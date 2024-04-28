// Copyright (c) 2022 Aiden
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
        text.replace(text.find("BFF"), 3, "best friend forever");
    }
    if (text.find("IDK") != -1)
    {
        text.replace(text.find("IDK"), 3, "I don't know");
    }
    if (text.find("JK") != -1)
    {
        text.replace(text.find("JK"), 2, "just kidding");
    }
    if (text.find("TMI") != -1)
    {
        text.replace(text.find("TMI"), 3, "too much information");
    }
    if (text.find("TTYL") != -1)
    {
        text.replace(text.find("TTYL"), 4, "talk to you later");
    }
    cout << "Expanded: " << text << endl;
    return 0;
}