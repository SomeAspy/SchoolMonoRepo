// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "Cat.h"
#include "Pet.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestPet()
    {
        Pet pet = Pet();
        pet.SetName("x");
        pet.SetAge(9);
        pet.PrintInfo();

        TS_ASSERT_EQUALS(9, pet.GetAge());
        TS_ASSERT_EQUALS("x", pet.GetName());
    }

    void TestCat()
    {
        Cat pet = Cat();
        pet.SetName("x");
        pet.SetAge(9);
        pet.PrintInfo();
        pet.SetBreed("y");

        TS_ASSERT_EQUALS(9, pet.GetAge());
        TS_ASSERT_EQUALS("x", pet.GetName());
        TS_ASSERT_EQUALS("y", pet.GetBreed());
    }
};
#endif /* NEWCXXTEST_H */
