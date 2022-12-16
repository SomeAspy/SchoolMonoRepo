#include <iostream>

using namespace std;

int DaysInFeb(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        return 29;
    }
    else
    {
        return 28;
    }
}

int main()
{
    int year;
    cin >> year;
    cout << year << " has " << DaysInFeb(year) << " days in February." << endl;
}