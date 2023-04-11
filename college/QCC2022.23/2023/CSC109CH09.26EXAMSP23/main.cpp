#include <iostream>
#include "Course.h"
using namespace std;

int main()
{
    Course course;
    cout << "Load course:" << endl;
    cout << "Opening file course1.txt" << endl;
    course.LoadFile("course1.txt");
    course.Print();
    course.PassCourse("passcourse1.txt");
    Course pCourse;
    cout << endl;
    cout << "Pass course:" << endl;
    cout << "Opening file passcourse1.txt" << endl;
    pCourse.LoadFile("passcourse1.txt");

    //    pCourse.Print();
    vector<Student>
        s = pCourse.GetRoster();
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << s.at(i) << endl;
    }
    return 0;
}
