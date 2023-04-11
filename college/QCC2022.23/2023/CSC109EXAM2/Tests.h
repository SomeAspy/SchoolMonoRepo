#define CSC109EXAM2_TESTS_H
#include <cxxtest/TestSuite.h>

#include "Student.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestBlankConstructor()
    {
        Student s1;
        TS_ASSERT_EQUALS(s1.GetName(), "");
    }
    void TestOverloadConstructor()
    {
        Student s1("Hloi");
        TS_ASSERT_EQUALS(s1.GetName(), "Hloi");
    }
    void TestSetName()
    {
        Student s1;
        s1.SetName("Hloi");
        TS_ASSERT_EQUALS(s1.GetName(), "Hloi");
    }
    void TestAddQuiz()
    {
        Student s1;
        s1.AddQuiz(100);
        TS_ASSERT_EQUALS(s1.GetTotalScores(), 100);
    }
    void TestGetTotalScores()
    {
        Student s1;
        s1.AddQuiz(100);
        s1.AddQuiz(100);
        TS_ASSERT_EQUALS(s1.GetTotalScores(), 200);
    }
    void TestGetAverageScores()
    {
        Student s1;
        s1.AddQuiz(100);
        s1.AddQuiz(50);
        TS_ASSERT_EQUALS(s1.GetAverageScores(), 75);
    }
    void TestOperatorLessThan()
    {
        Student s1;
        s1.AddQuiz(100);
        s1.AddQuiz(50);
        Student s2;
        s2.AddQuiz(100);
        s2.AddQuiz(100);
        TS_ASSERT(s1 < s2);
    }
    void TestOperatorGreaterThanOrEqual()
    {
        Student s1;
        s1.AddQuiz(100);
        s1.AddQuiz(50);
        Student s2;
        s2.AddQuiz(100);
        s2.AddQuiz(100);
        TS_ASSERT(s2 >= s1);
    }
};
