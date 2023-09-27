#define TEMPLATE_TESTS_H
#include <cxxtest/TestSuite.h>

#include "Course.h"
#include <fstream>
using namespace std;

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestDeclareAndReadStudent()
    {
        Student s("John", "Smith", 3.5);
        TS_ASSERT_EQUALS(s.GetFirst(), "John");
        TS_ASSERT_EQUALS(s.GetLast(), "Smith");
        TS_ASSERT_EQUALS(s.GetGPA(), 3.5);
    }
    void TestStudentOperatorOverride()
    {
        Student s("John", "Smith", 3.5);
        stringstream ss;
        ss << s;
        TS_ASSERT_EQUALS(ss.str(), "John Smith 3.5");
    }
    void TestCourseGetRoster()
    {
        Course c;
        Student s("John", "Smith", 3.5);
        c.AddStudent(s);
        TS_ASSERT_EQUALS(c.GetRoster().size(), 1);
        TS_ASSERT_EQUALS(c.GetRoster()[0].GetFirst(), "John");
        TS_ASSERT_EQUALS(c.GetRoster()[0].GetLast(), "Smith");
        TS_ASSERT_EQUALS(c.GetRoster()[0].GetGPA(), 3.5);
    }

    void TestCourseFindStudentHighestGpa()
    {
        Course c;
        Student s("John", "Smith", 3.5);
        c.AddStudent(s);
        Student s2("Jane", "Doe", 3.6);
        c.AddStudent(s2);
        TS_ASSERT_EQUALS(c.FindStudentHighestGpa().GetFirst(), "Jane");
        TS_ASSERT_EQUALS(c.FindStudentHighestGpa().GetLast(), "Doe");
        TS_ASSERT_EQUALS(c.FindStudentHighestGpa().GetGPA(), 3.6);
    }

    void TestCourseOperatorOverride()
    {
        Course c;
        Student s("John", "Smith", 3.5);
        c.AddStudent(s);
        Student s2("Jane", "Doe", 3.6);
        c.AddStudent(s2);
        stringstream ss;
        ss << c;
        TS_ASSERT_EQUALS(ss.str(), "John Smith 3.5\nJane Doe 3.6\n");
    }

    void TestCoursePassCourse()
    {
    }

    void TestCourseLoadFile()
    {
        Course c;
        c.LoadFile("course1.txt");
        TS_ASSERT_EQUALS(c.GetRoster().size(), 3);
        TS_ASSERT_EQUALS(c.GetRoster()[0].GetFirst(), "John");
        TS_ASSERT_EQUALS(c.GetRoster()[0].GetLast(), "Smith");
        TS_ASSERT_EQUALS(c.GetRoster()[0].GetGPA(), 3.5);
        TS_ASSERT_EQUALS(c.GetRoster()[1].GetFirst(), "Jane");
        TS_ASSERT_EQUALS(c.GetRoster()[1].GetLast(), "Doe");
        TS_ASSERT_EQUALS(c.GetRoster()[1].GetGPA(), 3.6);
        TS_ASSERT_EQUALS(c.GetRoster()[2].GetFirst(), "Joe");
        TS_ASSERT_EQUALS(c.GetRoster()[2].GetLast(), "Dirt");
        TS_ASSERT_EQUALS(c.GetRoster()[2].GetGPA(), 3.7);
    }

    void TestCoursePrint()
    {
        Course c;
        c.LoadFile("course1.txt");
        stringstream ss;
        ss << c;
        TS_ASSERT_EQUALS(ss.str(), "John Smith 3.5\nJane Doe 3.6\nJoe Dirt 3.7\n");
    }
};
