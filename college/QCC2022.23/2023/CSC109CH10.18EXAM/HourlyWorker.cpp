#include "HourlyWorker.h"

HourlyWorker::HourlyWorker(string name, double rate) : Worker(name, rate)
{
    this->name = name;
    this->rate = rate;
}

double HourlyWorker::computePay(int hours)
{
    if (hours <= 40)
    {
        return hours * rate;
    }
    else
    {
        return (40 * rate) + ((hours - 40) * (rate * 1.5));
    }
}
