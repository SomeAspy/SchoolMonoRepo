#include <iostream>
#include <string>

using namespace std;

string IntToReverseBinary(int num)
{
    string builder = "";
    while (num > 0)
    {
        builder += to_string(num % 2);
        num /= 2;
    }
    return builder;
}

string StringReverse(string str)
{
    string builder = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        builder += str[i];
    }
    return builder;
}

int main()
{
    int num;
    cin >> num;
    cout << StringReverse(IntToReverseBinary(num)) << endl;
}