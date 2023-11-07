// Copyright 2023
#ifndef OFFERED_COURSEH
#define OFFERED_COURSEH

#include "Course.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
// zybooks will freak out without these stupid includes

class OfferedCourse : public Course
{
    // TODO: Declare private data members
private:
    string instructorName;
    string location;
    string time;
    string term;

public:
    // TODO: Declare mutator functions -
    //      SetInstructorName(), SetLocation(), SetClassTime()
    void SetInstructorName(string instructorName);

    void SetLocation(string location);

    void SetClassTime(string time);

    void SetTerm(string term);

    // TODO: Declare accessor functions -
    //      GetInstructorName(), GetLocation(), GetClassTime()
    string GetInstructorName() const;

    string GetLocation() const;

    string GetClassTime() const;

    string GetTerm() const;
};

#endif
