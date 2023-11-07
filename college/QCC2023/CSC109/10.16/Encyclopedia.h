// Copyright 2023
#ifndef ENCYCLOPEDIAH
#define ENCYCLOPEDIAH

#include "Book.h"

class Encyclopedia : public Book
{
public:
    // TODO: Declare mutator functions -
    //       SetEdition(), SetNumPages()
    void SetEdition(string edition);

    void SetNumPages(int pages);

    void SetNumVolumes(int volumes);

    // TODO: Declare accessor functions -
    //       GetEdition(), GetNumPages()
    string
    GetEdition() const;
    int GetNumPages() const;
    int GetNumVolumes() const;

    // TODO: Declare a PrintInfo() function that overrides
    //       the PrintInfo() in Book class
    void PrintInfo() const;

    // TODO: Declare private data members
private:
    int pages;
    string edition;
    int volumes;
};

#endif
