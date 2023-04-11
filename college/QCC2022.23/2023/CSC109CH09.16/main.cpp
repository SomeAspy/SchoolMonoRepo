#include <iostream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::stringstream;

int DateParser(string month)
{
    int monthInt = 0;

    if (month == "January")
        monthInt = 1;
    else if (month == "February")
        monthInt = 2;
    else if (month == "March")
        monthInt = 3;
    else if (month == "April")
        monthInt = 4;
    else if (month == "May")
        monthInt = 5;
    else if (month == "June")
        monthInt = 6;
    else if (month == "July")
        monthInt = 7;
    else if (month == "August")
        monthInt = 8;
    else if (month == "September")
        monthInt = 9;
    else if (month == "October")
        monthInt = 10;
    else if (month == "November")
        monthInt = 11;
    else if (month == "December")
        monthInt = 12;
    return monthInt;
}

int main()
{

    // TODO: Read dates from input, parse the dates to find the ones
    //       in the correct format, and output in m-d-yyyy format

    while (true)
    {
        string input, month, day, dayOut, year;
        getline(cin, input);
        stringstream ss(input);
        ss >> month;
        if (month == "-1")
        {
            break;
        }
        int mInt = DateParser(month);
        if (mInt == 0)
        {
            continue;
        }

        ss >> day;

        if (day[day.size() - 1] != ',')
        {
            continue;
        }

        for (unsigned int i = 0; i < day.size(); ++i)
        {
            if (isdigit(day[i]))
            {
                dayOut += day[i];
            }
        }
        ss >> year;
        cout << mInt << '-' << dayOut << '-' << year << '\n';
    }
}
