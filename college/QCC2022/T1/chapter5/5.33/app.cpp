#include <iostream>

using namespace std;

void SwapValues(int &a, int &b, int &c, int &d)
{
    int temp = a;
    a = b;
    b = temp;
    temp = c;
    c = d;
    d = temp;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    SwapValues(a, b, c, d);
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
}