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
    int min1;
    min1 = v[0];
    long int min2 = 999999999999999999; // lol this is a terrible idea
    for (size_t i = 0; i < vSize; i++)
    {
        if (v[i] < min1)
        {
            min1 = v[i];
        }
    }

    for (size_t i = 0; i < vSize; i++)
    {
        if (v[i] < min2 && v[i] != min1)
        {
            min2 = v[i];
        }
    }

    cout << min1 << " and " << min2 << endl;
}