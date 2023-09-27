// Copyright 2023
#ifndef ARTISTH
#define ARTISTH

#include <string>
using std::string;

class Artist
{
public:
    Artist();

    Artist(string artistName, int birthYear, int deathYear);

    string GetName() const;

    int GetBirthYear() const;

    int GetDeathYear() const;

    void PrintInfo() const;

private:
    // TODO: Declare private data members - artistName, birthYear, deathYear
    string artistName;
    int birthYear;
    int deathYear;
};

#endif
