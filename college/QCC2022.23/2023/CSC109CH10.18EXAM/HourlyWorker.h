/*
•    Define a derived class named HourlyWorker that inherits from Worker. (25 points)
a.    Define a constructor for the HourlyWorker class that takes two arguments, name, rate, and initializes the corresponding data members.
b.    Override the computePay function in the HourlyWorker class to compute the pay for an hourly worker. An hourly worker gets paid the hourly wage for the actual number of hours worked if hours are less than or equal to 40. If the hourly worker worked more than 40 hours, he gets paid 1.5x for hours greater 40.  This function takes an integer argument hour and returns a double.

virtual void print(std::ostream& os) const {
        os << "Name: " << this->name << ", Hourly Rate: $" << this->rate;
    }
// Output operator
friend std::ostream& operator<<(std::ostream& os, const Worker& worker) {
        worker. Print(os);
        return os;
    }
*/

#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Worker.h"
#include <string>

using std::string;

class HourlyWorker : public Worker
{
public:
    HourlyWorker(string name, double rate);
    virtual double computePay(int hours);
    void print(std::ostream &os) const
    {
        os << "Name: " << this->name << ", Hourly Rate: $" << this->rate;
    }
};

#endif /* HOURLYWORKER_H */
