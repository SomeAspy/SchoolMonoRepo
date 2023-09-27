#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> v;
    size_t vSize;
    cin >> vSize;
    for (size_t i = 0; i < vSize; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    vector<unsigned int> counts(vSize, 0);

    for (size_t i = 0; i < vSize; i++)
    {
        for (size_t j = 0; j < vSize; j++)
        {
            if (v[i] == v[j])
            {
                counts[i]++;
            }
        }
    }

    for (size_t i = 0; i < vSize; i++)
    {
        cout << v[i] << " - " << counts[i] << endl;
    }
}