#include "Appointment.h"

Appointment::Appointment() {}

Appointment::Appointment(string desc, Time s, Time e)
{
    description = desc;
    start = s;
    end = e;
}

void Appointment::print() const
{
    cout << start.get_hours() << ":" << start.get_minutes() << " - " << end.get_hours() << ":" << end.get_minutes() << " " << description << endl;
}

void Appointment::read()
{
    int start_hours, start_mins, end_hours, end_mins;
    string desc;
    fstream in;
    in.open("appt.txt");
    in >> start_hours >> start_mins >> end_hours >> end_mins >> desc;
}
