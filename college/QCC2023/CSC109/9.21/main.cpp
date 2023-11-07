#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using std::cin;
using std::cout;
using std::getline;
using std::istringstream;
using std::remove_if;
using std::string;

int GetMonthAsInt(string month)
{
    if (month == "January")
        return 1;
    else if (month == "February")
        return 2;
    else if (month == "March")
        return 3;
    else if (month == "April")
        return 4;
    else if (month == "May")
        return 5;
    else if (month == "June")
        return 6;
    else if (month == "July")
        return 7;
    else if (month == "August")
        return 8;
    else if (month == "September")
        return 9;
    else if (month == "October")
        return 10;
    else if (month == "November")
        return 11;
    else if (month == "December")
        return 12;
    else
        return 0;
}

int main()
{
    string input, year, month;
    int day, mint;
    while (true)
    {
        getline(cin, input);
        if (input == "-1")
        {
            break;
        }
        if (input.find(',') == string::npos)
        {
            continue;
        }
        input.erase(input.find(','));
        istringstream ss(input);
        ss >> month >> day >> year;
        mint = GetMonthAsInt(month);
        if (mint == 0)
        {
            continue;
        }
        cout << mint << '-' << day << '-' << year << '\n';
    }
    return 0;
}