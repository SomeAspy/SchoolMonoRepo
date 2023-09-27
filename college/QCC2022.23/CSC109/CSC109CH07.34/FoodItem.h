#ifndef FOODITEMH
#define FOODITEMH

#include <string>

using namespace std;

class FoodItem
{
public:
    // TODO: Declare default constructor
    FoodItem();

    // TODO: Declare second constructor with parameters
    // to initialize private data members

    FoodItem(string name, double fat, double carbs, double protein);

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
