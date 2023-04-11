#include <iostream>
#include <vector>
using namespace std;

void SortVector(vector<int> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = i + 1; j < v.size(); j++)
        {
            if (v[i] > v[j])
            {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    // reverse vector
    for (size_t i = 0; i < v.size() / 2; i++)
    {
        int temp = v[i];
        v[i] = v[v.size() - i - 1];
        v[v.size() - i - 1] = temp;
    }
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
    SortVector(v);
    for (size_t i = 0; i < vSize; i++)
    {
        cout << v[i] << ",";
    }
    cout << endl;
}