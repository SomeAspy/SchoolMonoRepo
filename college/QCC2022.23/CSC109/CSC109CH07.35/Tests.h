#define TEMPLATE_TESTS_H
#include <cxxtest/TestSuite.h>

#include <string>
#include <sstream>
#include <iostream>
#include "Artwork.h"

using std::cout;
using std::streambuf;
using std::stringstream;

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestArtistConstructorNullAndGetters()
    {
        Artist Test;

        TS_ASSERT_EQUALS(Test.GetBirthYear(), -1);
        TS_ASSERT_EQUALS(Test.GetDeathYear(), -1);
        TS_ASSERT_EQUALS(Test.GetName(), "unknown");
    }

    void TestArtistConstructor()
    {
        Artist Test("a", 1, 2);

        TS_ASSERT_EQUALS(Test.GetBirthYear(), 1);
        TS_ASSERT_EQUALS(Test.GetDeathYear(), 2);
        TS_ASSERT_EQUALS(Test.GetName(), "a");
    }

    void TestArtistPrintInfoNull()
    {
        Artist Test;

        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        Test.PrintInfo();
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "Artist: unknown (unknown)\n");
    }

    void TestArtistPrintInfoAlive()
    {
        Artist Test("a", 1, -1);

        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        Test.PrintInfo();
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "Artist: a (1 to present)\n");
    }

    void TestArtistPrintInfoDead()
    {
        Artist Test("a", 1, 2);

        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        Test.PrintInfo();
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "Artist: a (1 to 2)\n");
    }

    void TestArtworkConstructorNullAndGetters()
    {
        Artwork Test;

        TS_ASSERT_EQUALS(Test.GetTitle(), "unknown");
        TS_ASSERT_EQUALS(Test.GetYearCreated(), -1);
    }

    void TestArtworkConstructor()
    {
        Artist a("a", 1, 2);
        Artwork Test("b", 3, a);

        TS_ASSERT_EQUALS(Test.GetTitle(), "b");
        TS_ASSERT_EQUALS(Test.GetYearCreated(), 3);
    }

    void TestArtworkPrintInfo()
    {
        Artist a("a", 1, 2);
        Artwork Test("b", 3, a);

        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        Test.PrintInfo();
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "Artist: a (1 to 2)\nTitle: b, 3\n");
    };
};
