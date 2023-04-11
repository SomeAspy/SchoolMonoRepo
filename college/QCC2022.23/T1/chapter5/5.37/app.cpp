#include <string>
#include <iostream>

using namespace std;

string RemoveNonAlpha(string str)
{
    string builder = "";
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            builder += str[i];
        }
    }
    return builder;
}

int main()
{
    string str;
    getline(cin, str);
    cout << RemoveNonAlpha(str) << endl;
}