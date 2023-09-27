// Copyright 2023
#include "Artwork.h"
#include <iostream>

using std::cout;

// TODO: Define default constructor
Artwork::Artwork()
{
    title = "unknown";
    yearCreated = -1;
}

// TODO: Define second constructor to initialize
//       private fields (title, yearCreated, artist)

Artwork::Artwork(string title, int yearCreated, Artist artist)
{
    this->title = title;
    this->yearCreated = yearCreated;
    this->artist = artist;
}

// TODO: Define get functions: GetTitle(), GetYearCreated()
string Artwork::GetTitle()
{
    return title;
}
int Artwork::GetYearCreated()
{
    return yearCreated;
}

// TODO: Define PrintInfo() function
//       Call the PrintInfo() function in the Artist class to print an artist's information
void Artwork::PrintInfo()
{
    artist.PrintInfo();
    cout << "Title: " << title << ", " << yearCreated << '\n';
}
