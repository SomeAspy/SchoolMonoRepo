/*
    Aiden B.
    See license at head of repository
    Summary: Savings account balance
    Time Spent: too long
    DOB: 10/16/24
    Output:
    > Enter the starting balance on the account: $1200
    > Enter the annual interest rate on the account (e.g. .04): .02
    > 0.00
    > Month 1
    > Total deposits for this month:    $100
    > Total withdrawals for this month: $30
    > Interest received this month: $2.06
    > Ending monthly balance $1272.06
    Notes: god this gave me a lot of pain, not because it was difficult, but because I'm stupid https://imgur.com/a/LQGKi4R
            Have you ever heard about having a rubber ducky to talk to? https://en.wikipedia.org/wiki/Rubber_duck_debugging
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::fixed;
using std::left;
using std::pow;
using std::right;
using std::setprecision;
using std::setw;

int main()
{
    float totalDeposits = 0, totalWithdrawals = 0, totalInterest = 0, balance = -1, rate = -1, userInput = -1;

    cout << "Enter the starting balance on the account: $";
    cin >> balance;
    cout << "Enter the annual interest rate on the account (e.g. .04): ";
    cin >> rate;
    cout << fixed << setprecision(2);

    const float initialBalance = balance;

    rate /= 12; // Annual -> Monthly

    for (int month = 1; month < 4; ++month)
    {

        const float monthStartBalance = balance;
        cout << "\nMonth " << month << '\n';

        // Get Deposit
        userInput = -1;
        while (true)
        {
            cout << "Total deposits for this month:    $";
            cin >> userInput;
            if (userInput < 0)
            {
                cout << "Deposits must be >0\n";
            }
            break;
        }
        balance += userInput;
        totalDeposits += userInput;

        // Get Withdrawal
        userInput = -1;
        while (true)
        {
            cout << "Total withdrawals for this month: $";
            cin >> userInput;
            if (userInput < 0)
            {
                cout << "Withdrawals must be >0\n";
            }
            break;
        }
        balance -= userInput;
        totalWithdrawals += userInput;

        // Do calculations
        float interest = rate * ((monthStartBalance + balance) / 2);
        balance += interest;
        totalInterest += interest;
        cout << "Interest received this month: $" << interest << "\nEnding monthly balance $" << balance << "\n";
    }

    // Final chart
    cout << "\nQuarterly Savings Account Statement\n\nStarting balance:     $" << right << setw(10) << initialBalance << left
         << "\nTotal deposits:     + $" << right << setw(10) << totalDeposits << left
         << "\nTotal withdrawals   - $" << right << setw(10) << totalWithdrawals << left // <- Turns into 1076475645313255735296.00
         << "\nTotal interest      + $" << right << setw(10) << totalInterest
         << '\n'
         << setw(33) << "__________"
         << left
         << "\nEnding balance:       $" << right << setw(10) << balance;
}