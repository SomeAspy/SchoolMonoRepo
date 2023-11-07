// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "Course.h"
#include "OfferedCourse.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestCourse()
    {
        Course course = Course();

        course.SetCourseNumber("x");
        course.SetCourseTitle("y");
        course.PrintInfo();

        TS_ASSERT_EQUALS(course.GetCourseNumber(), "x");
        TS_ASSERT_EQUALS(course.GetCourseTitle(), "y")
    }

    void TestOfferedCourse()
    {
        OfferedCourse course = OfferedCourse();

        course.SetCourseNumber("x");
        course.SetCourseTitle("y");
        course.PrintInfo();
        course.SetInstructorName("z");
        course.SetLocation("a");
        course.SetClassTime("b");
        course.SetTerm("c");

        TS_ASSERT_EQUALS(course.GetCourseNumber(), "x");
        TS_ASSERT_EQUALS(course.GetCourseTitle(), "y")
        TS_ASSERT_EQUALS(course.GetClassTime(), "b");
        TS_ASSERT_EQUALS(course.GetInstructorName(), "z");
        TS_ASSERT_EQUALS(course.GetLocation(), "a")
        TS_ASSERT_EQUALS(course.GetTerm(), "c");
    }
};
#endif /* NEWCXXTEST_H */
