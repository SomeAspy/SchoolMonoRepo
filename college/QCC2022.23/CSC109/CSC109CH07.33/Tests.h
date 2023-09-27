#define CSC109CH0733_TESTS_H
#include <cxxtest/TestSuite.h>

#include "Team.h"
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::streambuf;
using std::string;
using std::stringstream;

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestTeamName()
    {
        Team test = Team();
        test.SetName("Test");
        TS_ASSERT_EQUALS(test.GetName(), "Test");
    }

    void TestTeamWins()
    {
        Team test = Team();
        test.SetWins(10);
        TS_ASSERT_EQUALS(test.GetWins(), 10);
    }

    void TestTeamLosses()
    {
        Team test = Team();
        test.SetLosses(10);
        TS_ASSERT_EQUALS(test.GetLosses(), 10);
    }

    void TestTeamWinPercentage()
    {
        Team test = Team();
        test.SetWins(10);
        test.SetLosses(10);
        TS_ASSERT_EQUALS(test.GetWinPercentage(), 0.5);
    }

    void TestTeamPrintStandingWinning()
    {
        Team test = Team();
        test.SetName("Test");
        test.SetWins(75);
        test.SetLosses(25);
        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        test.PrintStanding();
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "Win percentage: 0.75\nCongratulations, Team Test has a winning average!\n");
    };

    void TestTeamPrintStandingLosing()
    {
        Team test = Team();
        test.SetName("Test");
        test.SetWins(25);
        test.SetLosses(75);
        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        test.PrintStanding();
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "Win percentage: 0.25\nTeam Test has a losing average.\n");
    };
};
