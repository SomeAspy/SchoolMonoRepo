//
// Created by hloi on 10/29/2021.
// 20 points

#ifndef CSC109CH09EXAM1_STUDENT_H
#define CSC109CH09EXAM1_STUDENT_H

#include <string>
using namespace std;

// Class representing a student
class Student
{
public:
    /**
     * Write a constructor for Student class with the following parameters
     * Initialize first, last, and gpa
     * @param first
     * @param last
     * @param gpa
     * (4 points)
     */
    Student(string first, string last, double gpa);

    /**
     * Write a GetGPA function
     * @return gpa
     * (2 points)
     */
    double GetGPA() const;

    /**
     * Write a GetLast function
     * @return last name
     * (2 points)
     */
    string GetLast() const;

    /**
     * Write a GetFirst function
     * @return first name
     * (2 points)
     */
    string GetFirst() const;

    /**
     * override stream operator<< and return first, last, gpa separate with a space and end with a newline
     * @param out
     * @param student
     * @return out
     * See course.txt for output format
     * You must use this stream operator<< for Course stream operator<<, print, and PassCourse functions
     * in Course.h to get full credits.
     *  (10 points)
     */
    friend ostream &operator<<(ostream &out, const Student &student);

private:
    // first name
    // last name
    // grade point average (double)
    string first;
    string last;
    double gpa;
};

#endif // CSC109CH09EXAM1_STUDENT_H
