// Copyright 2023
// See instruction
// add the following methods

// overload subtract operator; subtract T1-T2
// overload >= operator; T1 >= T2
#include <iostream>
#include "TimerHrMin.h"

using std::cout;

TimerHrMin::TimerHrMin()
{
    hr = 0;
    min = 0;
}

TimerHrMin::TimerHrMin(int hr, int min)
{
    this->hr = hr;
    this->min = min;
}

int TimerHrMin::GetHour() const
{
    return hr;
}

int TimerHrMin::GetMinute() const
{
    return min;
}

TimerHrMin TimerHrMin::operator-(TimerHrMin x)
{
    TimerHrMin result;
    if (min - x.min < 0)
    {
        result.min += 60;
        result.hr -= 1;
    }
    result.hr += hr - x.hr;
    result.min += min - x.min;
    return result;
}

bool TimerHrMin::operator>=(TimerHrMin x)
{
    if (hr > x.hr)
    {
        return true;
    }
    else if (hr == x.hr)
    {
        return min >= x.min;
    }
    else
    {
        return false;
    }
}

void TimerHrMin::Print(bool comma) const
{
    cout << "hour=" << hr;
    if (comma)
    {
        cout << ',';
    }
    cout << " minute=" << min << '\n';
}
