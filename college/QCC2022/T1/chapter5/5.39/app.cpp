#include <algorithm>
#include <iostream>

using namespace std;

int MaxNumber(int a, int b, int c, int d)
{
    return max(max(a, b), max(c, d));
}

int MinNumber(int a, int b, int c, int d)
{
    return min(min(a, b), min(c, d));
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << "Maximum is " << MaxNumber(a, b, c, d) << endl;
    cout << "Minimum is " << MinNumber(a, b, c, d) << endl;
}