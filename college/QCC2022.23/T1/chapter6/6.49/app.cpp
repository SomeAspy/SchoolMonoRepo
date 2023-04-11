#include <iostream>
#include <vector>
using namespace std;

int main()
{
    size_t vSize;
    cin >> vSize;

    vector<int> a(vSize);
    for (size_t i = 0; i < vSize; i++)
    {
        cin >> a[i];
    }

    for (size_t i = 0; i < vSize / 2; i++)
    {
        int temp = a[i];
        a[i] = a[vSize - i - 1];
        a[vSize - i - 1] = temp;
    }

    for (size_t i = 0; i < vSize; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
}