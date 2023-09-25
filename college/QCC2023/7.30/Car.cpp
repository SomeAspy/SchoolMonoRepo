// Copyright 2023
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Car.h"
using std::cout;
using std::fixed;
using std::setprecision;

void Car::SetModelYear(int userYear)
{
    modelYear = userYear;
}

int Car::GetModelYear() const
{
    return modelYear;
}

// TODO: Implement SetPurchasePrice() function
void Car::SetPurchasePrice(int userPrice)
{
    purchasePrice = userPrice;
}

// TODO: Implement GetPurchasePrice() function
int Car::GetPurchasePrice() const
{
    return purchasePrice;
}

void Car::CalcCurrentValue(int currentYear)
{
    double depreciationRate = 0.15;
    int carAge = currentYear - modelYear;

    // Car depreciation formula
    currentValue = purchasePrice * pow((1 - depreciationRate), carAge);
}

// TODO: Implement PrintInfo() function to output modelYear, purchasePrice, and
// currentValue
void Car::PrintInfo() const
{
    cout << fixed << setprecision(0) << "Car's information:\n  Model year: " << modelYear << "\n  Purchase price: $" << purchasePrice << "\n  Current value: $" << currentValue << '\n';
}

double Car::GetCurrentValue() const
{
    return currentValue;
}
