// Copyright 2023
#ifndef ARTWORKH
#define ARTWORKH

#include "Artist.h"

class Artwork
{
public:
    Artwork();

    Artwork(string title, int yearCreated, Artist artist);

    string GetTitle();

    int GetYearCreated();

    void PrintInfo();

private:
    // TODO: Declare private data members - title, yearCreated
    string title;
    int yearCreated;

    // TODO: Declare private data member artist of type Artist
    Artist artist;
};

#endif
