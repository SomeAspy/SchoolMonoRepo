#include <iostream>
#include <string>

using namespace std;

int GetNumOfWords(const string str) // stolen from 5.44
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

void replaceString(string &str, const string search, const string replace)
{
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str.substr(i, search.length()) == search)
        {
            str.replace(i, search.length(), replace);
        }
    }
}

void prompt()
{
    cout << "Enter s for search, r for replace, or q to quit:" << endl;
    char c;
    cin >> c;
    cin.ignore();
    while (c != 'q')
    {
        cout << "Enter a paragraph:" << endl;
        string s;
        getline(cin, s);
        int count;
        if (c == 's')
        {
            // write a function for search
            // return count of words
            count = GetNumOfWords(s);
        }
        else if (c == 'r')
        {
            cout << "Enter word to replace:" << endl;
            string word;
            getline(cin, word);
            cout << "Enter replacement word:" << endl;
            string replace;
            getline(cin, replace);
            replaceString(s, word, replace);
            // write a function for replace
            // return count of words
            // modify count of words and modified string
            count = GetNumOfWords(s);
        }
        cout << "Occurrences of word = " << count << endl;
        if (c == 'r')
        {
            cout << "New string: " << s << endl;
        }
        cout << "Enter s for search, r for replace, or q to quit:" << endl;
        cin >> c;
        cin.ignore();
    }
}

int main()
{
    prompt();
    return 0;
}