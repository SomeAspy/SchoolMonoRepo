#include <iostream>
#include <string>

using namespace std;

int GetNumOfCharacters(string str)
{
    return str.length();
}

void OutputWithoutWhitespace(string str)
{
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
        {
            cout << str[i];
        }
    }
}

int main()
{
    cout << "Enter a sentence or phrase:\n";
    string str;
    getline(cin, str);
    getline(cin, str);
    cout << "\nYou entered: " << str << endl;
    cout << "\nNumber of characters: " << GetNumOfCharacters(str) << endl;
    cout << "String with no whitespace: ";
    OutputWithoutWhitespace(str);
    cout << endl;
}