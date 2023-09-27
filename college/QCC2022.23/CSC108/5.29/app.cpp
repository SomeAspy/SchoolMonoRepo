#include <iostream>
#include <iomanip>

using namespace std;

double LapsToMiles(double laps)
{
    return laps * 0.25; // function that is used once, is one line - why does it need to be a function?
}

int main()
{
    double laps;
    cin >> laps;
    cout << fixed << setprecision(2) << LapsToMiles(laps) << endl;
}