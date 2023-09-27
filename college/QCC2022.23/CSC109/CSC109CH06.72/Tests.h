// Copyright [2023]
#define TESTS_H
#include <cxxtest/TestSuite.h>

#include "TwoDArray.h"

class tests : public CxxTest::TestSuite
{

public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void test_set_row()
    {
        double array[3][3]{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
        double row[3]{10, 11, 12};
        set_row(*array, 1, 3, row);
        TS_ASSERT_EQUALS(array[1][0], 10)
        TS_ASSERT_EQUALS(array[1][1], 11)
        TS_ASSERT_EQUALS(array[1][2], 12)
    }

    void test_get_row()
    {
        double array[3][3]{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
        double *rowReturn = get_row(*array, 0, 3);
        TS_ASSERT_EQUALS(1, rowReturn[0]);
        TS_ASSERT_EQUALS(2, rowReturn[1]);
        TS_ASSERT_EQUALS(3, rowReturn[2]);
    }

    void test_set_element()
    {
        double array[3][3]{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
        set_element(*array, 2, 3, 1, 99);
        TS_ASSERT_EQUALS(array[2][1], 99)
    }

    void test_get_element()
    {
        double array[3][3]{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
        TS_ASSERT_EQUALS(get_element(*array, 2, 3, 1), 8)
    }

    void test_sum()
    {
        double array[3][3]{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
        TS_ASSERT_EQUALS(sum(*array, 3, 3), 45)
    }

    void test_max()
    {
        double array[3][3]{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
        TS_ASSERT_EQUALS(find_max(*array, 3, 3), 9)
    }

    void test_min()
    {
        double array[3][3]{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
        TS_ASSERT_EQUALS(find_min(*array, 3, 3), 1)
    }
    void test_stringify()
    {
        double array[3][3]{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
        TS_ASSERT_EQUALS(to_string(*array, 3, 3), "      1.00      2.00      3.00\n      4.00      5.00      6.00\n      7.00      8.00      9.00\n")
    }
};
