#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool contains(string s, char c)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    unsigned int vSize;
    cin >> vSize;
    vector<string> v(vSize);
    for (size_t i = 0; i < vSize; i++)
    {
        cin >> v[i];
    }
    char c;
    cin >> c;
    for (size_t i = 0; i < vSize; i++)
    {
        if (contains(v[i], c))
        {
            cout << v[i] << ',';
        }
    }
}