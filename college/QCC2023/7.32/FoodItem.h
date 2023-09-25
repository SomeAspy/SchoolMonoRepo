// Copyright 2023
#ifndef FOODITEMH
#define FOODITEMH

#include <string>

using std::string;

class FoodItem
{
public:
    // TODO: Declare default constructor
    FoodItem();

    // TODO: Declare second constructor with parameters
    // to initialize private data members
    FoodItem(string nameIn, double fatIn, double carbsIn, double proteinIn);

    string GetName();

    double GetFat();

    double GetCarbs();

    double GetProtein();

    double GetCalories(double numServings);

    void PrintInfo();

private:
    string name;
    double fat;
    double carbs;
    double protein;
};

#endif
