// Copyright 2023
#include "Artist.h"
#include "Artwork.h"
#include <iostream>
#include <string>

using std::cin;
using std::getline;
using std::string;

int main()
{
    string userTitle, userArtistName;
    int yearCreated, userBirthYear, userDeathYear;

    getline(cin, userArtistName);
    getline(cin, userTitle);
    cin >> userBirthYear;
    cin >> userDeathYear;
    cin >> yearCreated;

    Artist userArtist = Artist(userArtistName, userBirthYear, userDeathYear);

    Artwork newArtwork = Artwork(userTitle, yearCreated, userArtist);

    newArtwork.PrintInfo();
    return 0;
}
