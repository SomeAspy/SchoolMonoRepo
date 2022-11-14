#include <iostream>
#include <string>

using namespace std;

void PrintMenu()
{
    cout << "MENU\nc - Number of non-whitespace characters\nw - Number of words\nf - Find text\nr - Replace all !'s\ns - Shorten spaces\nq - Quit\n";
}

int GetNumOfNonWSCharacters(const string str)
{
    int count = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
        {
            count++;
        }
    }
    return count;
}

int GetNumOfWords(const string str)
{
    int count = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            if (str[i + 1] != ' ' && str[i + 1] != '\t')
            {
                count++;
            }
        }
    }
    return count + 1;
}

int FindText(const string search, const string str)
{
    int count = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == search[0])
        {
            if (str.substr(i, search.length()) == search)
            {
                count++;
            }
        }
    }
    return count;
}

void ReplaceExclamation(string &str)
{
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == '!')
        {
            str[i] = '.';
        }
    }
}

void ShortenSpace(string &str)
{
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            if (str[i + 1] == ' ' || str[i + 1] == '\t')
            {
                str.erase(i, 1);
                i--;
            }
        }
    }
}

void ExecuteMenu(char choice, string &str)
{
    string search; // guh
    switch (choice)
    {
    case 'q':
        exit(0);
    case 'c':
        cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(str) << endl;
        cout << endl;
        break;
    case 'w':
        cout << "Number of words: " << GetNumOfWords(str) << endl;
        cout << endl;
        break;
    case 'f':
        cout << "Enter a word or phrase to be found:\n";
        cin.ignore();
        getline(cin, search);
        cout << "\"" << search << "\" instances: " << FindText(search, str) << endl;
        cout << endl;
        break;
    case 'r':
        ReplaceExclamation(str);
        cout << "Edited text: " << str << endl;
        cout << endl;
        break;
    case 's':
        ShortenSpace(str);
        cout << "Edited text: " << str << endl;
        cout << endl;
    }
}

int main()
{
    string str;
    cout << "Enter a sample text:\n\n";
    getline(cin, str);
    cout << "You entered: " << str << endl;
    cout << endl;
    while (true)
    {
        PrintMenu();
        cout << "\nChoose an option:\n"; // Why tf doesn't this go under the menu?
        char choice;
        cin >> choice;
        ExecuteMenu(choice, str);
    }
}