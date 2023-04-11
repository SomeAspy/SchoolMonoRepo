/*
•	Define another derived class named SalariedWorker that also inherits from Worker. (25 points)
a.	Define a constructor for the SalariedWorker class that takes two arguments, name and rate, and initializes
the corresponding data members.
b.	Override the computePay function in the SalariedWorker class to compute the pay for a salaried worker.
A salaried worker gets paid the hourly wage for 40 hours, no matter what the actual number of hours is.
This function takes an integer argument hours and returns a double.
c.	Override the print function in in the Worker class with the following output stringstream (no newline):
Name: Jane, Weekly Rate: $50

*/

#ifndef SALARIEDWORKER_H
#define SALARIEDWORKER_H

#include "Worker.h"
#include <string>

using std::string;

class SalariedWorker : public Worker
{
public:
    SalariedWorker(string name, double rate);
    virtual double computePay(int hours);
    void print(std::ostream &os) const
    {
        os << "Name: " << this->name << ", Weekly Rate: $" << this->rate;
    }
};

#endif /* SALARIEDWORKER_H */
