#include "Time.h"

Time::Time(int hour, int min, int sec)
{
    time_in_secs = hour * 3600 + min * 60 + sec;
}

Time::Time()
{
    time_in_secs = 0;
}

int Time::get_hours() const
{
    return time_in_secs / 3600;
}

int Time::get_minutes() const
{
    return (time_in_secs % 3600) / 60;
}

int Time::get_seconds() const
{
    return time_in_secs % 60;
}

int Time::seconds_from(Time t) const
{
    return time_in_secs - t.time_in_secs;
}

void Time::add_seconds(int s)
{
    time_in_secs += s;
}
