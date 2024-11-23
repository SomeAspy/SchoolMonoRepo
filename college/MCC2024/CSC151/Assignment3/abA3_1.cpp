/*
    Aiden B.
    See license at head of repository
    Summary: Hospital Bill
    Time Spent: 45m
    DOB: 11/17/24
    Output:
    > This program will compute the patient hospital charges.
    > Enter I for in-patient or O for out-patient: i
    >
    > Number of days in the hospital: 5
    > Daily room rate: $100
    > Lab fees and other service charges: $120
    > Medication charges: $400
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::fixed;
using std::left;
using std::ofstream;
using std::right;
using std::setprecision;
using std::setw;

bool isValid(double value)
{
    if (value > 0)
    {
        return true;
    }
    return false;
}

bool isValid(char value)
{
    if (value == 'i' || value == 'o')
    {
        return true;
    }
    return false;
}

double patientCharges(double days, double rate, double fees, double meds)
{
    // nothing changes, as unused values are initialized as 0
    return (days * rate) + fees + meds;
}

int main()
{
    ofstream outputFile("hospital.txt");
    char mode = 'X';
    double days = 0;
    double rate = 0;
    double fees = 0;
    double meds = 0;

    while (!isValid(mode))
    {
        cout << "This program will compute the patient hospital charges.\nEnter I for in-patient or O for out-patient: ";
        cin >> mode;
        mode = tolower(mode);
    }
    if (mode == 'i')
    {
        while (!isValid(days))
        {
            cout << "\nNumber of days in the hospital: ";
            cin >> days;
        }
        while (!isValid(rate))
        {
            cout << "Daily room rate: $";
            cin >> rate;
        }
    }
    while (!isValid(fees))
    {
        cout << "Lab fees and other service charges: $";
        cin >> fees;
    }
    while (!isValid(meds))
    {
        cout << "Medication charges: $";
        cin >> meds;
    }

    const double total = patientCharges(days, rate, fees, meds);

    outputFile << "\n**************************"
               << "\nHospital Billing Statement"
               << "\n**************************";

    if (mode == 'i')
    {
        outputFile << "\nRoom charges    $" << right << setw(8) << rate * days << left;
    }
    outputFile << setprecision(2) << fixed
               << "\nLab & Services  $" << right << setw(8) << fees << left
               << "\nMedication      $" << right << setw(8) << meds << left
               << "\nTotal charges   $" << right << setw(8) << total
               << "\n**************************";
    outputFile.close();
}