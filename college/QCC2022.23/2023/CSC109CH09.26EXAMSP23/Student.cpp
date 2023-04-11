#include "Student.h"
#include <iostream>
#include <string>

// type your code here
Student::Student(string first, string last, double gpa)
{
    this->first = first;
    this->last = last;
    this->gpa = gpa;
}

double Student::GetGPA() const
{
    return gpa;
}

string Student::GetLast() const
{
    return last;
}

string Student::GetFirst() const
{
    return first;
}

ostream &operator<<(ostream &out, const Student &student)
{
    out << student.first << " " << student.last << " " << student.gpa;
    return out;
}
