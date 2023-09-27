// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "Team.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestGetSet()
    {
        Team x;
        x.SetTeamLosses(999);
        x.SetTeamName("xyz");
        x.SetTeamWins(10);

        TS_ASSERT_EQUALS(x.GetTeamWins(), 10);
        TS_ASSERT_EQUALS(x.GetTeamName(), "xyz");
        TS_ASSERT_EQUALS(x.GetTeamLosses(), 999);
    }

    void TestPrint()
    {
        Team x;
        x.SetTeamLosses(999);
        x.SetTeamName("xyz");
        x.SetTeamWins(10);

        x.PrintStanding();

        Team y;
        y.SetTeamLosses(1);
        y.SetTeamName("xyz");
        y.SetTeamWins(-9999);

        y.PrintStanding();
    }

    void TestLogic()
    {
        Team x;
        x.SetTeamLosses(999);
        x.SetTeamName("xyz");
        x.SetTeamWins(10);

        TS_ASSERT_DELTA(0.00991080277502, x.GetWinPercentage(), .01);
    }
};
#endif /* NEWCXXTEST_H */
