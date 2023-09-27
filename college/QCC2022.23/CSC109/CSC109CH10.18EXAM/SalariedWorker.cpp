#include "SalariedWorker.h"

SalariedWorker::SalariedWorker(string name, double rate) : Worker(name, rate)
{
    this->name = name;
    this->rate = rate;
}

double SalariedWorker::computePay(int hours)
{
    return 40 * rate;
}
