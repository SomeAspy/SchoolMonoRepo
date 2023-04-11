#include <iostream>
#include <iomanip>

using namespace std;

int FeetToSteps(double feet)
{
    return feet / 2.5;
}

int main()
{
    double feet;
    cin >> feet;
    cout << fixed << setprecision(2) << FeetToSteps(feet) << endl;
}