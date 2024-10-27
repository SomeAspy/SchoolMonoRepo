/*
    Aiden B.
    See license at head of repository
    Summary: calculate loan payments
    Time Spent: 20m
    DOB: 9/15/24
    Notes: This appears to round up to cents, but that is an acceptable margin of error in my opinion
*/

#include <iostream>
#include <iomanip>
#include <cmath>

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
    int paymentCount;
    float rate, loan;

    cout << "Loan amount: $";
    cin >> loan;
    cout << "\nAnnual interest rate (in the format .12 (for 12%)): ";
    cin >> rate;
    rate /= 12; // Annual -> Monthly
    cout
        << "\nNumber of monthly payments to be made: ";
    cin >> paymentCount;

    float monthlyPayment = ((rate * pow(rate + 1, paymentCount)) / (pow(rate + 1, paymentCount) - 1)) * loan;

    cout
        << "\n\n - - Loan Report - -\n"
        << "\nLoan Amount:            $" << setw(9) << fixed << setprecision(2) << loan
        << "\nMonthly Interest Rate:" << setw(11) << rate * 100 << "%"
        << "\nNumber of Payments:" << setw(15) << paymentCount
        << "\nMonthly Payment:        $" << setw(9) << monthlyPayment
        << "\nAmount Paid Back:       $" << setw(9) << monthlyPayment * paymentCount
        << "\nInterest Paid:          $" << setw(9) << (monthlyPayment * paymentCount) - loan
        << "\n";
}