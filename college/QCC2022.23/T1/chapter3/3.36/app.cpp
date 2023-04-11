
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

float taxBracket(float tax1, float tax2, float income)
{
    float cash;
    if (income <= tax1)
    {
        return income * .15;
    }
    else if (income <= tax1 + tax2)
    {
        cash = tax1 * .15;
        income -= tax1;
        cash += income * .28;
    }
    else
    {
        cash = tax1 * .15;
        income -= tax1;
        cash += tax2 * .28;
        income -= tax2;
        cash += income * .31;
    }
    return cash;
}

float tax(float income, char status)
{
    if (status == 'S')
    {
        return taxBracket(21450, 30450, income);
    }
    else
    {
        return taxBracket(35800, 50700, income);
    }
}

void prompt()
{
    cout << "Please enter your income: ";
    float income;
    cin >> income;

    cout << "Please enter S for single or M for married: ";
    char status;
    cin >> status;
    cout << "The tax is " << tax(income, status) << endl;
}

int main()
{
    prompt();

    float taxOut = tax(32000, 'M');
    assert(fabs(taxOut - 4800) < .00001);

    taxOut = tax(50000, 'M');
    assert(fabs(taxOut - 9346) < .00001);

    taxOut = tax(100000, 'M');
    assert(fabs(taxOut - 23751) < .00001);

    taxOut = tax(20000, 'S');
    assert(fabs(taxOut - 4800) < .00001);

    taxOut = tax(50000, 'S');
    assert(fabs(taxOut - 9346) < .00001);

    taxOut = tax(100000, 'S');
    assert(fabs(taxOut - 23751) < .00001);

    return 0;
}