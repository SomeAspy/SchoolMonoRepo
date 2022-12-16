#include <iostream>
#include <algorithm>

using namespace std;

int MaxMagnitude(int a, int b, int c)
{
    int af = abs(a);
    int bf = abs(b);
    int cf = abs(c);

    if (af > bf && af > cf)
    {
        return a;
    }
    else if (bf > af && bf > cf)
    {
        return b;
    }
    else
    {
        return c;
    }
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << MaxMagnitude(a, b, c) << endl;
}