#include "FoodItem.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Define default constructor

FoodItem::FoodItem()
{
    name = "Water";
    fat = 0.0;
    carbs = 0.0;
    protein = 0.0;
}

// Define second constructor with parameters
// to initialize private data members

FoodItem::FoodItem(string name, double fat, double carbs, double protein)
{
    this->name = name;
    this->fat = fat;
    this->carbs = carbs;
    this->protein = protein;
}

string FoodItem::GetName()
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
