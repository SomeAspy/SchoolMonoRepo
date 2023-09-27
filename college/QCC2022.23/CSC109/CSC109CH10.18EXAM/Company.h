/*
•	Define a class named Company that contains a vector of Worker pointers and company name and the following
member functions (25 points):
a.	Define a constructor for the Company class that takes one string argument, company_name, and initializes
the corresponding data members.
b.	Define the get methods for the company name (getName).
c.	Define the get methods for the vector workers (getWorkers).
d.	Define a destructor that deletes all the Worker objects in the vector.
e.	Define a member function named addWorker that takes a Worker pointer as an argument and adds it to the vector.
f.	Define a member function named removeWorker that takes a Worker pointer as an argument and removes it from
the vector.  Must use operator== from the worker class to get full credit for this function.
g.	Define a member function named computeTotalPay that takes an integer argument hours and returns the total
pay for all the workers in the vector for the given number of hours. This function should use the computePay
function of each worker to compute the pay and add it up.
h.	Define the operator= for the Worker class to copy the name and rate of one Worker object to another.
i.	Define the operator<< for the Worker class to output the name and rate of a Worker object.
You must use the operator<< from the Worker class to get full credit for this function.
Add a newline for each worker output at this function.
*/

#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
#include "Worker.h"

using std::vector;

class Company
{
public:
    Company(string company_name);
    string getName() const;
    vector<Worker *> getWorkers() const;
    // virtual ~Company();
    void addWorker(Worker *worker);
    void removeWorker(Worker *worker);
    double computeTotalPay(int hours) const;
    friend ostream &operator<<(ostream &os, const Company &company);
    int getNumWorkers() const;

private:
    string company_name;
    vector<Worker *> workers;
};

#endif /* COMPANY_H */
