#include <iostream>
#include <vector>
using namespace std;

int main()
{
    size_t vSize;
    cin >> vSize;
    vector<int> v(vSize);
    for (size_t i = 0; i < vSize; i++)
    {
        cin >> v[i];
    }
    int max;
    cin >> max;
    for (size_t i = 0; i < vSize; i++)
    {
        if (v[i] <= max)
        {
            cout << v[i] << ",";
        }
    }
    cout << endl;
}