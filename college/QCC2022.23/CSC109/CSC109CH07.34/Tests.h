#define TEMPLATE_TESTS_H
#include <cxxtest/TestSuite.h>

#include "FoodItem.h"
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

    void TestFoodItemConstructorAndGetters()
    {
        FoodItem Test;
        TS_ASSERT_DELTA(Test.GetFat(), .0, .001);
        TS_ASSERT_DELTA(Test.GetCarbs(), .0, .001);
        TS_ASSERT_DELTA(Test.GetProtein(), .0, .001);
        TS_ASSERT_EQUALS(Test.GetName(), "Water")
    }

    void TestFoodItemConstructor()
    {
        FoodItem Test("Test", 1.0, 2.0, 3.0);
        TS_ASSERT_DELTA(Test.GetFat(), 1.0, .001);
        TS_ASSERT_DELTA(Test.GetCarbs(), 2.0, .001);
        TS_ASSERT_DELTA(Test.GetProtein(), 3.0, .001);
        TS_ASSERT_EQUALS(Test.GetName(), "Test")
    }
    void TestGetCalories()
    {
        FoodItem Test("Test", 1.0, 2.0, 3.0);
        TS_ASSERT_DELTA(Test.GetCalories(1.0), 29.0, .001);
    }

    void TestPrintInfo()
    {
        FoodItem Test("Test", 1.0, 2.0, 3.0);
        streambuf *sbuf = cout.rdbuf();
        stringstream ss;
        cout.rdbuf(ss.rdbuf());
        Test.PrintInfo();
        cout.rdbuf(sbuf);
        TS_ASSERT_EQUALS(ss.str(), "Nutritional information per serving of Test:\n  Fat: 1.00 g\n  Carbohydrates: 2.00 g\n  Protein: 3.00 g\n");
    };
};
