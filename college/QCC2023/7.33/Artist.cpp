// Copyright 2023
#include "Artist.h"
#include <iostream>

using std::cout;

// TODO: Define default constructor
Artist::Artist()
{
    artistName = "unknown";
    birthYear = -1;
    deathYear = -1;
}

// TODO: Define second constructor to initialize
//       private fields (artistName, birthYear, deathYear)
Artist::Artist(string artistName, int birthYear, int deathYear)
{
    this->artistName = artistName;
    this->birthYear = birthYear;
    this->deathYear = deathYear;
}

// TODO: Define get functions: GetName(), GetBirthYear(), GetDeathYear()
string Artist::GetName() const
{
    return artistName;
}
int Artist::GetBirthYear() const
{
    return birthYear;
}
int Artist::GetDeathYear() const
{
    return deathYear;
}

// TODO: Define PrintInfo() function
//      If deathYear is entered as -1, only print birthYear

void Artist::PrintInfo() const
{
    cout << "Artist: " << artistName << " (";
    if (birthYear != -1 && deathYear != -1)
    {
        cout << birthYear << " to " << deathYear;
    }
    else if (birthYear != -1)
    {
        cout << birthYear << " to present";
    }
    else
    {
        cout << "unknown";
    }
    cout << ")\n";
}
