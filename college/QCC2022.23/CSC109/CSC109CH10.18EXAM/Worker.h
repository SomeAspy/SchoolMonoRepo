// implement a worker class
/*
Define a base class named Worker with two protected data members: name of type string and rate of type double (25 points).
a.    Define a constructor for the Worker class that takes two arguments, name and rate, and initializes the corresponding data members (since the name and rate are protected, that mean the spelling of name and rate must match).
b.    Define a virtual function named computePay that takes an integer argument hours and returns a double. The default for the worker gets paid the hourly wage for the actual number of hours worked, i.e., hours * rate.  This function will be overridden in the derived classes to compute the pay for each type of worker.
c.    Define the get methods for the name and rate (getName, getRate).
d.    Define the operator== for the Worker class to compare two Worker objects based on their name and rate.
e.    Overridden functions that compare two workers based on their name and rate.
f.    Overridden functions operator<< for the worker class.  Call a virtual print function that takes an ostream argument.  You are given these two functions in the worker class and you override the print function in the derived classes.
Output stringstream example (no newline):
    Name: John, Hourly Rate: $15

*/

#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <ostream>

using std::ostream;
using std::string;

class Worker
{
protected:
    string name;
    double rate;

public:
    Worker(string name, double rate);
    virtual double computePay(int hours);
    string getName() const;
    double getRate() const;
    bool operator==(const Worker &other) const;
    virtual void print(std::ostream &os) const
    {
        os << "Name: " << this->name << ", Hourly Rate: $" << this->rate;
    }
    // Output operator
    friend std::ostream &operator<<(std::ostream &os, const Worker &worker)
    {
        worker.print(os);
        return os;
    }
};

#endif /* WORKER_H */
