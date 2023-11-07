#include "Time.h"
#include <time.h>

using std::time;

Time::Time(int hour, int min, int sec)
{
    time_in_secs = hour * 3600;
    time_in_secs += min * 60;
    time_in_secs += sec;
}

Time::Time()
{
    // running this breaks all other logic, oh no.
    time_in_secs = time(nullptr);
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
    return (time_in_secs % 3600) % 60;
}

int Time::seconds_from(Time t) const
{
    return abs(time_in_secs - t.time_in_secs);
}

void Time::add_seconds(int s)
{
    time_in_secs += s;
}

bool Time::operator==(Time timeR) const
{
    return time_in_secs == timeR.time_in_secs;
}

void Time::operator=(Time timeR)
{
    time_in_secs = timeR.time_in_secs;
}
