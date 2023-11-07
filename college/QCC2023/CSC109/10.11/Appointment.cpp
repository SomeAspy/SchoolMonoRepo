#include "Appointment.h"
#include <string>
#include <iostream>
#include <ostream>

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::string;

Appointment::Appointment()
{
    description = "No Description";
    start = Time();
    end = Time();
    end.add_seconds(3600);
}

Appointment::Appointment(string desc, Time s, Time e)
{
    description = desc;
    start = s;
    end = e;
}

void Appointment::print() const
{
    string mp = ""; // char does not allow empty;
    if (start.get_minutes() < 10)
    {
        mp = '0';
    }
    cout << start.get_hours() << ':' << mp << start.get_minutes() << " - " << end.get_hours() << ':';
    if (end.get_minutes() < 10)
    {
        mp = '0';
    }
    else
    {
        mp = "";
    }
    cout << mp << end.get_minutes() << "  " << description << '\n';
}

void Appointment::read()
{
    int sh, sm, eh, em;
    cin >> sh >> sm >> eh >> em >> description;
    start.add_seconds((sh * 3600) + (sm * 60));
    end.add_seconds((eh * 3600) + (em * 60));
}

void Appointment::save(ostream &out) const
{
    out << start.get_hours() << ' ' << start.get_minutes() << ' ' << end.get_hours() << ' ' << end.get_minutes() << ' ' << description << '\n';
}

void Appointment::load(istream &in)
{
    int sh, sm, eh, em;
    in >> sh >> sm >> eh >> em >> description;
    start.add_seconds((sh * 3600) + (sm * 60));
    end.add_seconds((eh * 3600) + (em * 60));
}

Appointment::~Appointment()
{
    // explode
}
