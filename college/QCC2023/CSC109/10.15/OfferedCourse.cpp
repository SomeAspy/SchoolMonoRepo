// Copyright 2023
#include "OfferedCourse.h"

// TODO: Define mutator functions -
//      SetInstructorName(), SetLocation(), SetClassTime()
void OfferedCourse::SetInstructorName(string instructorName)
{
    this->instructorName = instructorName;
}

void OfferedCourse::SetLocation(string location)
{
    this->location = location;
}

void OfferedCourse::SetClassTime(string time)
{
    this->time = time;
}

void OfferedCourse::SetTerm(string term)
{
    this->term = term;
}

// TODO: Define accessor functions -
//      GetInstructorName(), GetLocation(), GetClassTime()
string OfferedCourse::GetInstructorName() const
{
    return instructorName;
}

string OfferedCourse::GetLocation() const
{
    return location;
}

string OfferedCourse::GetClassTime() const
{
    return time;
}

string OfferedCourse::GetTerm() const
{
    return term;
}
