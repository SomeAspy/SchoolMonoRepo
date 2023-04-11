#include <string>
#include <iostream>

using namespace std;

string CreateAcronym(string str)
{
    string builder = "";
    for (unsigned int i = 0; i < str.length(); ++i)
    {
        if (i == 0)
        {
            builder += toupper(str[i]);
            builder += '.';
        }
        else if (str[i] == ' ' && isupper(str[i + 1]))
        {
            builder += toupper(str[i + 1]);
            builder += '.';
        }
    }
    return builder;
}

int main()
{
    string str;
    getline(cin, str);
    cout << CreateAcronym(str) << endl;
}