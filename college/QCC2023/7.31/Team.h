// Copyright 2023
#ifndef TEAMH
#define TEAMH

#include <string>

using std::string;

class Team
{
    // TODO: Declare private data members - name, wins, losses
private:
    string name;
    int wins;
    int losses;

public:
    // TODO: Declare mutator functions -
    //       SetName(), SetWins(), SetLosses()
    void SetTeamName(string nameIn);
    void SetTeamWins(int winsIn);
    void SetTeamLosses(int lossesIn);

    // TODO: Declare accessor functions -
    //       GetName(), GetWins(), GetLosses()
    string GetTeamName() const;
    int GetTeamWins() const;
    int GetTeamLosses() const;

    // TODO: Declare GetWinPercentage()
    double GetWinPercentage() const;

    // TODO: Declare PrintStanding()
    void PrintStanding() const;
};

#endif
