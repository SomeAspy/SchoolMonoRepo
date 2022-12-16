// Copyright (C) 2022 Aiden Baker
//
// This file is part of SchoolMonoRepo.
//
// SchoolMonoRepo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SchoolMonoRepo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SchoolMonoRepo.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <string>

using namespace std;

int menu()
{
    cout << "Enter s for search, r for replace, or q to quit:\n";
    char choice;
    cin >> choice;
    cout << choice << endl;
    switch (choice)
    {
    case 's':
        return 1;
    case 'r':
        return 2;
    case 'q':
        cout << "Program terminated.\n";
        exit(0);
    default:
        return -1;
    }
}

int main()
{
    while (true)
    {
        string paragraph;
        int choice = menu();
        cout << "Enter a paragraph:\n";
        getline(cin, paragraph);
        getline(cin, paragraph);
        cout << paragraph << endl;
        string search;
        string search2, replace;
        int results2 = 0;
        int results = 0;
        switch (choice)
        {
        case 1:
            cout << "Enter a word to search:\n";
            cin >> search;
            cout << search << endl;
            for (unsigned int i = 0; i < paragraph.length(); ++i)
            {
                size_t found = paragraph.find(search, i);
                if (found != string::npos)
                {
                    results += 1;
                    i = found;
                }
            }
            cout << "Occurrences of Word = " << results << endl;
            break;
        case 2:
            cout << "Enter a word to search:\n";

            cin >> search2;
            cout << search2 << endl;
            cout << "Enter word to replace:\n";
            cin >> replace;
            cout << replace << endl;

            for (unsigned int i = 0; i < paragraph.length(); ++i)
            {
                size_t found = paragraph.find(search2, i);
                if (found != string::npos)
                {
                    results2 += 1;
                    i = found;
                    paragraph.replace(found, search2.length(), replace);
                }
            }
            cout << "New string: " << paragraph << endl;
            cout << "Occurrences of Word = " << results2 << endl;
        }
    }
}