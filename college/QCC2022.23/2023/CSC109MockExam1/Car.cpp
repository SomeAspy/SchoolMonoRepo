#include "Car.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::fixed;
using std::setprecision;

int Car::ID = 100;

string Car::getMake()
{
    return make;
}

string Car::getModel()
{
    return model;
}

string Car::getColor()
{
    return color;
}

double Car::getCost()
{
    return cost;
}

Car Car::setDetails(string make, string model, string color, double cost)
{
    this->make = make;
    this->model = model;
    this->color = color;
    this->cost = cost;
    return *this;
}

Car Car::setID(int carID)
{
    this->carID = carID;
    return *this;
}

Car::Car()
{
    carID = ID;
    ID++;
}

bool Car::operator==(Car &otherCar)
{
    return this->carID == otherCar.carID &&
           this->make == otherCar.make &&
           this->model == otherCar.model &&
           this->color == otherCar.color &&
           this->cost == otherCar.cost;
}

void Car::print()
{
    cout << "Make: " << make << '\n'
         << "Model: " << model << '\n'
         << "Color: " << color << '\n'
         << "Cost: $" << setprecision(4) << fixed << cost << '\n'
         << "ID: " << carID << '\n';
}
