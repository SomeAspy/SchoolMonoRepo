// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence, search;

    cout << "Enter a sentence: ";

    getline(cin, sentence);

    cout << "Enter a word to search for: ";

    getline(cin, search);

    int index = sentence.find(search);

    if (index != -1)
    {
        cout << "Found " << search << " at index " << index << " to " << index + search.length() - 1 << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    return 0;
}