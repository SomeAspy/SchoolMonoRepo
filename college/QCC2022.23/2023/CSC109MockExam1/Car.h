#ifndef CAR_H
#define CAR_H
#include <string>

using std::string;

class Car
{
public:
    string getMake();
    string getModel();
    string getColor();
    double getCost();
    Car setDetails(string make = "unspecified", string model = "unspecified", string color = "unspecified", double cost = -1);
    Car setID(int carID);
    bool operator==(Car &otherCar);
    void print();

private:
    static int ID;
    int carID;
    string make;
    string model;
    string color;
    double cost;
};

#endif CAR_H
