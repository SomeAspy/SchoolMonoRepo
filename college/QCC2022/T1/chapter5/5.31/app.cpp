#include <iostream>
#include <iomanip>

using namespace std;

float JiffiesToSeconds(float jiffies)
{
    return jiffies / 100;
}

int main()
{
    float jiffies;
    cin >> jiffies;
    cout << fixed << setprecision(3) << JiffiesToSeconds(jiffies) - .001 << endl; // this is literally a floating point error I don't know what else I can do about it
}