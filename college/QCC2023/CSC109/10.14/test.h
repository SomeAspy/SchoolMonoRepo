// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "Instrument.h"
#include "StringInstrument.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestInstrument()
    {
        Instrument x = Instrument();
        x.SetName("name");
        x.SetManufacturer("manufacturer");
        x.SetYearBuilt(1);
        x.SetCost(9);
        x.PrintInfo();

        TS_ASSERT_EQUALS(x.GetName(), "name");
        TS_ASSERT_EQUALS(x.GetCost(), 9);
        TS_ASSERT_EQUALS(x.GetManufacturer(), "manufacturer");
        TS_ASSERT_EQUALS(x.GetYearBuilt(), 1);
    }

    void TestStringInstrument()
    {
        StringInstrument x = StringInstrument();
        x.SetName("name");
        x.SetManufacturer("manufacturer");
        x.SetYearBuilt(1);
        x.SetCost(9);
        x.PrintInfo();
        x.SetIsBowed(true);
        x.SetNumOfFrets(10);
        x.SetNumOfStrings(5);

        TS_ASSERT_EQUALS(x.GetName(), "name");
        TS_ASSERT_EQUALS(x.GetCost(), 9);
        TS_ASSERT_EQUALS(x.GetManufacturer(), "manufacturer");
        TS_ASSERT_EQUALS(x.GetYearBuilt(), 1);
        TS_ASSERT_EQUALS(x.GetIsBowed(), true);
        TS_ASSERT_EQUALS(x.GetNumOfFrets(), 10);
        TS_ASSERT_EQUALS(x.GetNumOfStrings(), 5)
    }
};
#endif /* NEWCXXTEST_H */
