#include <iostream>
#include "Course.h"
#include <fstream>
using namespace std;

// type your code here

vector<Student> Course::GetRoster() const
{
    return roster;
}

Student Course::FindStudentHighestGpa() const
{
    Student highest = roster[0];
    for (unsigned int i = 1; i < roster.size(); i++)
    {
        if (roster[i].GetGPA() > highest.GetGPA())
        {
            highest = roster[i];
        }
    }
    return highest;
}

void Course::AddStudent(Student student)
{
    roster.push_back(student);
}

ostream &operator<<(ostream &out, const Course &course)
{
    for (unsigned int i = 0; i < course.roster.size(); i++)
    {
        out << course.roster[i] << endl;
    }
    return out;
}

int Course::PassCourse(string fileName) const
{
    ofstream outFile;
    outFile.open(fileName);
    if (!outFile)
    {
        return 1;
    }
    for (unsigned int i = 0; i < roster.size(); i++)
    {
        if (roster[i].GetGPA() >= 74)
        {
            outFile << roster[i];
        }
    }
    outFile.close();
    return 0;
}

int Course::LoadFile(string fileName)
{
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile)
    {
        return 1;
    }
    string first, last;
    double gpa;
    while (inFile >> first >> last >> gpa)
    {
        Student student(first, last, gpa);
        AddStudent(student);
    }
    inFile.close();
    return 0;
}

void Course::Print() const
{
    cout << *this;
}
