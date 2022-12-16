#include <iostream>
#include <string>

using namespace std;

int CalcNumCharacters(string str, char chr)
{
    int count = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == chr)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string str;
    char chr;
    int count;
    cin >> chr >> str;
    count = CalcNumCharacters(str, chr);
    cout << count << ' ' << chr;
    if (count == 0 || count > 1)
    {
        cout << "'s";
    }
    cout << endl;
}