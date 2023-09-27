#define CSC109CH07_32_TESTS_H
#include <cxxtest/TestSuite.h>

#include "Car.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void ExampleTest()
    {
        // Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        TS_ASSERT_EQUALS(1, 1); // This test will pass.
        TS_ASSERT_EQUALS(1, 2); // This test will fail.
    }
};
