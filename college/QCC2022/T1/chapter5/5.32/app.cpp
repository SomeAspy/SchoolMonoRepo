#include <iostream>
#include <iomanip>

using namespace std;

double DrivingCost(double mpg, double cost, double distance)
{
    return (distance / mpg) * cost;
}

int main()
{
    double mpg, cost;
    cin >> mpg >> cost;
    cout << fixed << setprecision(2) << DrivingCost(mpg, cost, 10) << ' ';
    cout << fixed << setprecision(2) << DrivingCost(mpg, cost, 50) << ' ';
    cout << fixed << setprecision(2) << DrivingCost(mpg, cost, 400) << endl;
}