// implement your code here
#include "Worker.h"

Worker::Worker(string name, double rate)
{
    this->name = name;
    this->rate = rate;
}

double Worker::computePay(int hours)
{
    return hours * rate;
}

string Worker::getName() const
{
    return name;
}

double Worker::getRate() const
{
    return rate;
}

bool Worker::operator==(const Worker &worker) const
{
    return (this->name == worker.name && this->rate == worker.rate);
}
