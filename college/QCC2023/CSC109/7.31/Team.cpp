// Copyright 2023
#include <iostream>
#include <iomanip>
#include "Team.h"
using std::cout;
using std::fixed;
using std::setprecision;

// TODO: Implement mutator functions -
//       SetName(), SetWins(), SetLosses()

void Team::SetTeamName(string nameIn)
{
    name = nameIn;
}
void Team::SetTeamWins(int winsIn)
{
    wins = winsIn;
}
void Team::SetTeamLosses(int lossesIn)
{
    losses = lossesIn;
}

// TODO: Implement accessor functions -
//       GetName(), GetWins(), GetLosses()

string Team::GetTeamName() const
{
    return name;
}
int Team::GetTeamWins() const
{
    return wins;
}
int Team::GetTeamLosses() const
{
    return losses;
}

// TODO: Implement GetWinPercentage()
double Team::GetWinPercentage() const
{
    return static_cast<double>(wins) / static_cast<double>(wins + losses);
}

// TODO: Implement PrintStanding()
void Team::PrintStanding() const
{
    double winPercent = GetWinPercentage();
    cout << fixed << setprecision(2) << "Win percentage: " << winPercent << '\n';
    if (winPercent < .5)
    {
        cout << "Team " << name << " has a losing average.\n";
    }
    else
    {
        cout << "Congratulations, Team " << name << " has a winning average!\n";
    }
}
