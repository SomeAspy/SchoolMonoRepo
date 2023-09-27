//
// Created by hloi on 10/29/2021.
// 50 points
//

#ifndef CSC109CH09EXAM1_COURSE_H
#define CSC109CH09EXAM1_COURSE_H

#include <vector>
#include "Student.h"

class Course
{
public:
    /**
     * Write a function GetRoster to return the vector of students
     * @return roster
     * (5 points)
     */
    vector<Student>
    GetRoster() const;

    /**
     * Write a function FindStudentHighestGpa find the highest GPA from the vector roster;
     * @return a student object with the highest GPA
     * (10 points)
     */
    Student FindStudentHighestGpa() const;

    /**
     * Write a function AddStudent add a student to the vector roster
     * @param student
     * (5 points)
     */
    void AddStudent(Student student);

    /**
     * Overload stream operator<< to output all the student objects
     * You must use the overload stream operator<< from the student class,
     * otherwise, you will only get 5 points instead
     * (10 points)
     *
     */
    friend ostream &operator<<(ostream &out, const Course &course);
    /**
     * Write a function to select students with a GPA greater than 74 and save them to a file
     * @param fileName
     * @return 0 = success and 1 = fail
     * write the students with a GPA >= 74 to a file using the overload stream operator<< in Student.h and
     * stream operator<< for the Course.h
     * if you don't use the overload stream operator<<, you will get 5 points instead
     * See course.txt for output format.
     * (10 points)
     */
    int PassCourse(string fileName) const;

    /**
     * Write a function LoadFile to load a student file into roster
     * @param fileName
     * @return 0 = success and 1 = fail
     * See course.txt for input file format
     * (10 points)
     */
    int LoadFile(string fileName);

    /**
     * Write a function Print out the student roster
     * if you don't use the overload stream operator<<, you will get 5 points instead
     * See course.txt for output format.
     * (10 point)
     */
    void Print() const;

private:
    // collection of Student objects using vector
    vector<Student> roster;
};

#endif // CSC109CH09EXAM1_COURSE_H
