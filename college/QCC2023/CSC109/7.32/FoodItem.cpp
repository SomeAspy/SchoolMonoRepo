// Copyright 2023
#include "FoodItem.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::string;

// Define default constructor
FoodItem::FoodItem()
{
    name = "Water";
    fat = 0.0;
    carbs = 0.0;
    protein = 0.0;
}

FoodItem::FoodItem(string nameIn, double fatIn, double carbsIn, double proteinIn)
{
    name = nameIn;
    fat = fatIn;
    carbs = carbsIn;
    protein = proteinIn;
}

// Define second constructor with parameters
// to initialize private data members

string
FoodItem::GetName()
{
    return name;
}

double FoodItem::GetFat()
{
    return fat;
}

double FoodItem::GetCarbs()
{
    return carbs;
}

double FoodItem::GetProtein()
{
    return protein;
}

double FoodItem::GetCalories(double numServings)
{
    // Calorie formula
    double calories = ((fat * 9) + (carbs * 4) + (protein * 4)) * numServings;
    return calories;
}

void FoodItem::PrintInfo()
{
    cout << fixed << setprecision(2);
    cout << "Nutritional information per serving of " << name << ":" << endl;
    cout << "  Fat: " << fat << " g" << endl;
    cout << "  Carbohydrates: " << carbs << " g" << endl;
    cout << "  Protein: " << protein << " g" << endl;
}
