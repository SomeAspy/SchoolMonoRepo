#ifndef TEAMH
#define TEAMH

#include <string>

using namespace std;

class Team
{
private:
    string name;
    int wins;
    int losses;

public:
    Team();
    Team(string name, int wins, int losses);
    void SetName(string name);
    void SetWins(int wins);
    void SetLosses(int losses);
    string GetName();
    int GetWins();
    int GetLosses();
    double GetWinPercentage();
    void PrintStanding();
};

#endif
