#include <iostream>
#include <vector>
using namespace std;

int GetMaxInt(vector<int> v)
{
    int max = v[0];
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    return max;
}

int main()
{
    size_t vSize;
    cin >> vSize;
    vector<int> v(vSize);
    for (size_t i = 0; i < vSize; i++)
    {
        cin >> v[i];
    }
    int max = GetMaxInt(v);
    for (size_t i = 0; i < vSize; i++)
    {
        if (v[i] <= max)
        {
            cout << max - v[i] << " ";
        }
    }
    cout << endl;
}