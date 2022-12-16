#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vect1;
    int value;
    int i;

    cin >> value;
    while (value != 0)
    {
        vect1.push_back(value);
        cin >> value;
    }

    for (i = 0; i < vect1.size(); ++i)
    {
        if (vect1[i - 1] < vect1[i])
        {
            cout << "MISSED\n";
        }
        else
        {
            cout << vect1[i] << endl;
        }
    }

    return 0;
}