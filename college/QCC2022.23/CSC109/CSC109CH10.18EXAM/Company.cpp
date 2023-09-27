#include "Company.h"

Company::Company(string company_name)
{
    this->company_name = company_name;
}

string Company::getName() const
{
    return company_name;
}

vector<Worker *> Company::getWorkers() const
{
    return workers;
}

void Company::addWorker(Worker *worker)
{
    workers.push_back(worker);
}

void Company::removeWorker(Worker *worker)
{
    for (unsigned int i = 0; i < workers.size(); ++i)
    {
        if (workers[i] == worker)
        {
            workers.erase(workers.begin() + i);
        }
    }
}

double Company::computeTotalPay(int hours) const
{
    double total_pay = 0.0;
    for (unsigned int i = 0; i < workers.size(); i++)
    {
        total_pay += workers[i]->computePay(hours);
    }
    return total_pay;
}

// Company::~Company()
// {
//     for (unsigned int i = 0; i < workers.size(); i++)
//     {
//         delete workers[i];
//     }
// }

ostream &operator<<(ostream &os, const Company &company)
{
    for (unsigned int i = 0; i < company.getWorkers().size(); i++)
    {
        os << *company.getWorkers()[i] << '\n';
    }
    return os;
}

int Company::getNumWorkers() const
{
    return workers.size();
}
