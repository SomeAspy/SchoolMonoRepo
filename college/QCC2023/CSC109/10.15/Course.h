// Copyright 2023
#ifndef COURSEH
#define COURSEH

#include <string>

using std::string;

class Course
{
    // TODO: Declare private data members
private:
    string courseNumber;
    string courseTitle;

public:
    // TODO: Declare mutator functions
    //       SetCourseNumber(), SetCourseTitle()
    void SetCourseNumber(string courseNumber);
    void SetCourseTitle(string courseTitle);

    // TODO: Declare accessor functions -
    //       GetCourseNumber(), GetCourseTitle()
    string GetCourseNumber() const;
    string GetCourseTitle() const;

    // TODO: Declare PrintInfo()
    virtual void PrintInfo() const;
};

#endif
