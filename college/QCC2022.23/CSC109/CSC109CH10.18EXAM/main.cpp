#include <iostream>
#include <vector>
#include "Worker.h"
#include "HourlyWorker.h"
#include "SalariedWorker.h"
#include "Company.h"
#include "Company.cpp"
#include "HourlyWorker.cpp"
#include "SalariedWorker.cpp"
#include "Worker.cpp"

int main()
{
    std::string name = "Acme Corp.";
    Company c(name);

    Worker *worker1 = new HourlyWorker("John", 15.0);
    SalariedWorker *worker2 = new SalariedWorker("Jane", 50.0);
    HourlyWorker *worker3 = new HourlyWorker("Jim", 20.0);

    // Add some workers to the company
    c.addWorker(worker1);
    c.addWorker(worker2);
    c.addWorker(worker3);

    // Compute the total payroll for 40 hours and 45 hours
    std::cout << "Total payroll for 40 hours: $" << c.computeTotalPay(40) << std::endl;
    std::cout << "Total payroll for 45 hours: $" << c.computeTotalPay(45) << std::endl;

    // Print out the company's workers and their weekly pay
    std::cout << c;

    // Make a copy of the company and print it out
    Company copy = c;
    std::cout << "Copy of company:" << std::endl
              << copy;

    // Remove a worker from the company and print it out again
    c.removeWorker(worker2);
    std::cout << "Company after removing Jane:" << std::endl
              << c;

    return 0;
}
