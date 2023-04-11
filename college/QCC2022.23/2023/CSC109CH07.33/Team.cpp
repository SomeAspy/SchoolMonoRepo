#include <iostream>
#include <iomanip>
#include "Team.h"
#include <string>
using namespace std;

Team::Team(){};

void Team::SetName(string name)
{
    this->name = name;
}

void Team::SetWins(int wins)
{
    this->wins = wins;
}

void Team::SetLosses(int losses)
{
    this->losses = losses;
}

string Team::GetName()
{
    return name;
}

int Team::GetWins()
{
    return wins;
}

int Team::GetLosses()
{
    return losses;
}

// TODO: Implement GetWinPercentage()

double Team::GetWinPercentage()
{
    return (double)wins / (wins + losses);
}

// TODO: Implement PrintStanding()

void Team::PrintStanding()
{
    cout << "Win percentage: " << fixed << setprecision(2) << GetWinPercentage() << endl;
    if (GetWinPercentage() > 0.5)
    {
        cout << "Congratulations, Team " << name << " has a winning average!" << endl;
    }
    else
    {
        cout << "Team " << name << " has a losing average." << endl;
    }
}
