// Copyright 2023
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
#include "Book.h"
#include "Encyclopedia.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestBook()
    {
        Book book = Book();
        book.SetTitle("a");
        book.SetAuthor("b");
        book.SetPublisher("c");
        book.SetPublicationDate("d");
        book.PrintInfo();

        TS_ASSERT_EQUALS(book.GetTitle(), "a");
        TS_ASSERT_EQUALS(book.GetAuthor(), "b");
        TS_ASSERT_EQUALS(book.GetPublisher(), "c");
        TS_ASSERT_EQUALS(book.GetPublicationDate(), "d");
    }

    void TestEncyclopedia()
    {
        Encyclopedia book = Encyclopedia();
        book.SetTitle("a");
        book.SetAuthor("b");
        book.SetPublisher("c");
        book.SetPublicationDate("d");
        book.SetEdition("e");
        book.SetNumPages(1);
        book.SetNumVolumes(2);
        book.PrintInfo();

        TS_ASSERT_EQUALS(book.GetTitle(), "a");
        TS_ASSERT_EQUALS(book.GetAuthor(), "b");
        TS_ASSERT_EQUALS(book.GetPublisher(), "c");
        TS_ASSERT_EQUALS(book.GetPublicationDate(), "d");
        TS_ASSERT_EQUALS(book.GetEdition(), "e");
        TS_ASSERT_EQUALS(book.GetNumPages(), 1)
        TS_ASSERT_EQUALS(book.GetNumVolumes(), 2);
    }
};
#endif /* NEWCXXTEST_H */
