#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    while (true)
    {
        int n;
        cin >> n;
        if (n < 0)
        {
            break;
        }
        v.push_back(n);
    }

    if (v.size() > 9)
    {
        cout << "Too many numbers" << endl;
        return 0;
    }

    cout << "Middle item: " << v[v.size() / 2] << endl;
}