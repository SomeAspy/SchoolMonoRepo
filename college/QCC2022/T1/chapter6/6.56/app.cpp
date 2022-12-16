#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    vector<double> v;
    size_t vSize;
    cin >> vSize;
    for (size_t i = 0; i < vSize; i++)
    {
        double n;
        cin >> n;
        v.push_back(n);
    }

    double max = v[0];
    for (size_t i = 1; i < vSize; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    for (size_t i = 0; i < vSize; i++)
    {
        cout << fixed << setprecision(2) << v[i] / max << " ";
    }

    cout << endl;
}