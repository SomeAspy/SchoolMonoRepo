/*
    Aiden B.
    See license at head of repository
    Summary: RPS
    Time Spent: 1h - too much time debugging stupid mistakes
    DOB: 11/17/24
    Output:
    > Game Menu
    > ---------
    > 1) Rock
    > 2) Paper
    > 3) Scissors
    > 4) Quit
    >
    > Enter your choice: 1
    > You selected: Rock
    > The computer selected: Paper
    > Computer wins! Paper wraps Rock.
*/

#include <iostream>
#include <string>
#include <ctime>

using std::cin;
using std::cout;
using std::string;
using std::time;

/*
0: Rock
1: Paper
2: Scissors
*/

const string object[3] = {"Rock", "Paper", "Scissors"};
const string verb[3] = {"smashes", "wraps", "cuts"};

int returnWinning(int player, int cpu)
{
    // no breaks, because return does that.
    // This is the most efficient way I could think of
    switch (player + cpu)
    {
    case 1:
        return 1;
    case 2:
        return 0;
    case 3:
        return 2;
    }
}

string whoWon(int playerChoice, int winningValue)
{
    if (playerChoice == winningValue)
    {
        return "YOU win!";
    }
    return "Computer wins!";
}

int main()
{
    while (true)
    {
        int input = 0;
        srand(time(NULL)); // make a new seed for random, otherwise weird stuff happens
        const int cpuChoice = rand() % 3;
        while (input < 1 || input > 4)
        {
            cout << "Game Menu\n"
                 << "---------\n"
                 << "1) Rock\n"
                 << "2) Paper\n"
                 << "3) Scissors\n"
                 << "4) Quit\n\n"
                 << "Enter your choice: ";
            cin >> input;
            if (input == 4)
            {
                exit(0);
            }
        }
        input -= 1; // match to array starting at 0
        cout << "You selected: " << object[input]
             << "\nThe computer selected: " << object[cpuChoice] << '\n';
        if (cpuChoice == input)
        {
            cout << "\nTie. No winner.\n\n";
            continue;
        }
        const int winningValue = returnWinning(input, cpuChoice);

        cout << whoWon(input, winningValue) << ' ' << object[winningValue] << ' ' << verb[winningValue] << ' ' << object[(winningValue == input ? cpuChoice : input)] << ".\n";
        break;
    }
}