#ifndef ARTISTH
#define ARTISTH

#include <string>
using namespace std;

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
    string artistName;
    int birthYear;
    int deathYear;
};

#endif
