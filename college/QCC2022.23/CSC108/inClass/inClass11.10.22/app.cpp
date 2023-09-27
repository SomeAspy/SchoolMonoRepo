
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

double weekly_Salary(double weeklyHours, double WEEKLY_LIMIT, double hourlyWage)
{
    double weeklySalary = 0, overtimeHours = 0;
    if (weeklyHours <= WEEKLY_LIMIT)
    {
        weeklySalary = weeklyHours * hourlyWage;
    }
    else if (weeklyHours <= 80)
    {
        overtimeHours = weeklyHours - WEEKLY_LIMIT;
        weeklySalary = static_cast<int>((hourlyWage * WEEKLY_LIMIT) + (hourlyWage * overtimeHours * 1.5));
    }
    else
    {
        weeklySalary = -1;
    }
    return weeklySalary;
}

void prompt()
{
    int hourlyWage, weeklyHours, weeklySalary;
    const int WEEKLY_LIMIT = 40;

    cout << "Enter hourly wage: \n";
    cin >> hourlyWage;

    weeklyHours = 40;
    double salary = weekly_Salary(weeklyHours, WEEKLY_LIMIT, hourlyWage);
}

int main()
{
    // prompt();

    // whitebox testing
    double salary = weekly_Salary(31, 40, 30);
    assert(fabs(salary - 900) < 0.000001);

    salary = weekly_Salary(40, 40, 30);
    assert(fabs(salary - 1200) < 0.000001);

    salary = weekly_Salary(60, 40, 30);
    assert(fabs(salary - 2100) < 0.000001);

    salary = weekly_Salary(100, 40, 30);
    assert(salary == -1);
    return 0;
}