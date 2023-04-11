#include "CarList.h"

CarList CarList::add(Car car)
{
    for (unsigned int i = 0; i < cars.size(); ++i)
    {
        if (cars.at(i) == car)
        {
            return *this;
        }
    }
    cars.push_back(car);
    return *this;
}

CarList CarList::del(Car car)
{
    for (unsigned int i = 0; i < cars.size(); ++i)
    {
        if (cars[i] == car)
        {
            cars.erase(cars.begin() + i);
        }
    }
    return *this;
}

void CarList::print()
{
    for (unsigned int i = 0; i < cars.size(); ++i)
    {
        cars[i].print();
    }
}
