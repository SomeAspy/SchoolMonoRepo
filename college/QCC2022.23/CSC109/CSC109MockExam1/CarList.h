#ifndef CARLIST_H
#define CARLIST_H
#include <string>
#include "Car.h"
#include <vector>
using std::vector;

class CarList
{
public:
    CarList add(Car car);
    CarList del(Car car);
    void print();

private:
    vector<Car> cars;
};

#endif CARLIST_H
