#include <vector>
#include <iostream>

using namespace std;

void modifyPlayerCL(vector<int> &jerseys, vector<int> &ratings, const int player)
{
    cout << "Enter player " << player + 1 << "'s jersey number:\n";
    cin >> jerseys[player];
    cout << "Enter player " << player + 1 << "'s rating:\n\n";
    cin >> ratings[player];
}

void printRoster(const vector<int> jerseys, const vector<int> ratings)
{
    cout << "ROSTER" << endl;
    for (size_t i = 0; i < jerseys.size(); i++)
    {
        cout << "Player " << i + 1 << " -- Jersey number: " << jerseys[i] << ", Rating: " << ratings[i] << endl;
    }
}

char printMenu()
{
    char option;
    cout << "\nMENU" << endl;
    cout << "a - Add player" << endl;
    cout << "d - Remove player" << endl;
    cout << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;
    cin >> option;
    return option;
}

void addPlayer(vector<int> &jerseys, vector<int> &ratings)
{
    int jersey;
    int rating;
    cout << "Enter a new player's jersey number:\n";
    cin >> jersey;
    cout << "Enter the player's rating:\n";
    cin >> rating;
    jerseys.push_back(jersey);
    ratings.push_back(rating);
}

void delPlayer(vector<int> &jerseys, vector<int> &ratings)
{
    int jersey;
    cout << "Enter a jersey number:\n";
    cin >> jersey;
    for (size_t i = 0; i < jerseys.size(); i++)
    {
        if (jerseys[i] == jersey)
        {
            jerseys.erase(jerseys.begin() + i);
            ratings.erase(ratings.begin() + i);
        }
    }
}

void updateRating(const vector<int> &jerseys, vector<int> &ratings)
{
    int jersey;
    int rating;
    cout << "Enter a jersey number:\n";
    cin >> jersey;
    cout << "Enter a new rating for player:\n";
    cin >> rating;
    for (size_t i = 0; i < jerseys.size(); i++)
    {
        if (jerseys[i] == jersey)
        {
            ratings[i] = rating;
        }
    }
}

void above(const vector<int> &jerseys, const vector<int> &ratings)
{
    int rating;
    cout << "Enter a rating:\n";
    cin >> rating;
    cout << "ABOVE " << rating << endl;
    for (size_t i = 0; i < jerseys.size(); i++)
    {
        if (ratings[i] > rating)
        {
            cout << "Player " << i + 1 << " -- Jersey number: " << jerseys[i] << ", Rating: " << ratings[i] << endl;
        }
    }
}

int main()
{
    vector<int> jerseys(5);
    vector<int> ratings(5);

    for (size_t i = 0; i < 5; i++)
    {
        modifyPlayerCL(jerseys, ratings, i);
    }
    printRoster(jerseys, ratings);
    while (true)
    {
        switch (printMenu())
        {
        case 'q':
            exit(0);
        case 'o':
            printRoster(jerseys, ratings);
            break;
        case 'a':
            addPlayer(jerseys, ratings);
            break;
        case 'd':
            delPlayer(jerseys, ratings);
            break;
        case 'u':
            updateRating(jerseys, ratings);
            break;
        case 'r':
            above(jerseys, ratings);
            break;
        }
    }
}