// Copyright 2023
#include "Course.h"

#include <iostream>

using std::cout;

// TODO: Define mutator functions -
//       SetCourseNumber(), SetCourseTitle()
void Course::SetCourseNumber(string courseNumber)
{
    this->courseNumber = courseNumber;
}

void Course::SetCourseTitle(string courseTitle)
{
    this->courseTitle = courseTitle;
}

// TODO: Define accessor functions -
//       GetCourseNumber(), GetCourseTitle()
string Course::GetCourseNumber() const
{
    return courseNumber;
}

string Course::GetCourseTitle() const
{
    return courseTitle;
}

// TODO: Define PrintInfo()
void Course::PrintInfo() const
{
    cout << "Course Information:\n   Course Number: " << courseNumber << "\n   Course Title: " << courseTitle << '\n';
}
