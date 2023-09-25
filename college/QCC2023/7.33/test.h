// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "Artwork.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestArtistGetSet()
    {
        Artist x;
        TS_ASSERT_EQUALS(x.GetBirthYear(), -1);
        TS_ASSERT_EQUALS(x.GetDeathYear(), -1);
        TS_ASSERT_EQUALS(x.GetName(), "unknown");

        Artist y("xyz", 100, 456);
        TS_ASSERT_EQUALS(y.GetBirthYear(), 100);
        TS_ASSERT_EQUALS(y.GetDeathYear(), 456);
        TS_ASSERT_EQUALS(y.GetName(), "xyz");
    }
    void TestArtistPrint()
    {
        Artist x("xyz", 1, 33);
        x.PrintInfo();

        Artist y("xyz", 200, -1);
        y.PrintInfo();

        Artist z("xyz", -1, -1);
        z.PrintInfo();
    }
    void TestArtwork()
    {
        Artwork x;
        TS_ASSERT_EQUALS(x.GetTitle(), "unknown");
        TS_ASSERT_EQUALS(x.GetYearCreated(), -1);

        Artist a;
        Artwork y("xyz", 200, a);
        TS_ASSERT_EQUALS(x.GetTitle(), "unknown");
        TS_ASSERT_EQUALS(x.GetYearCreated(), -1);
        y.PrintInfo();
    }
};
#endif /* NEWCXXTEST_H */
