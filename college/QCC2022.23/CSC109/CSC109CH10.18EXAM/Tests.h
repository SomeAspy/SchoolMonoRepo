#define TEMPLATE_TESTS_H
#include <cxxtest/TestSuite.h>
#include "Company.h"
#include "SalariedWorker.h"
#include "HourlyWorker.h"

using std::string;

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestWorkerConstructor()
    {
        Worker *worker = new Worker("John", 15.0);
        TS_ASSERT_EQUALS(worker->getName(), "John");
        TS_ASSERT_EQUALS(worker->getRate(), 15.0);
    }

    void TestWorkerComputePay()
    {
        Worker *worker = new Worker("John", 15.0);
        TS_ASSERT_EQUALS(worker->computePay(40), 600.0);
        TS_ASSERT_EQUALS(worker->computePay(45), 675.0);
    }

    void TestWorkerEquality()
    {
        Worker *worker1 = new Worker("John", 15.0);
        Worker *worker2 = new Worker("John", 15.0);
        Worker *worker3 = new Worker("Jane", 15.0);
        Worker *worker4 = new Worker("John", 20.0);

        TS_ASSERT_EQUALS(*worker1, *worker2);
        TS_ASSERT_DIFFERS(*worker1, *worker3);
        TS_ASSERT_DIFFERS(*worker1, *worker4);
    }

    void TestWorkerGetters()
    {
        Worker *worker = new Worker("John", 15.0);
        TS_ASSERT_EQUALS(worker->getName(), "John");
        TS_ASSERT_EQUALS(worker->getRate(), 15.0);
    }

    void TestHourlyWorkerConstructor()
    {
        HourlyWorker *worker = new HourlyWorker("John", 15.0);
        TS_ASSERT_EQUALS(worker->getName(), "John");
        TS_ASSERT_EQUALS(worker->getRate(), 15.0);
    }

    void TestHourlyWorkerComputePay()
    {
        HourlyWorker *worker = new HourlyWorker("John", 15.0);
        TS_ASSERT_EQUALS(worker->computePay(40), 600.0);
        TS_ASSERT_EQUALS(worker->computePay(45), 712.5);
    }

    void TestSalariedWorkerConstructor()
    {
        SalariedWorker *worker = new SalariedWorker("John", 15.0);
        TS_ASSERT_EQUALS(worker->getName(), "John");
        TS_ASSERT_EQUALS(worker->getRate(), 15.0);
    }

    void TestSalariedWorkerComputerPay()
    {
        SalariedWorker *worker = new SalariedWorker("John", 15.0);
        TS_ASSERT_EQUALS(worker->computePay(40), 600.0);
    }

    void TestCompanyConstructor()
    {
        string name = "Acme Corp.";
        Company c(name);
        TS_ASSERT_EQUALS(c.getName(), "Acme Corp.");
    }

    void TestCompanyAddWorker()
    {
        string name = "Acme Corp.";
        Company c(name);

        Worker *worker1 = new HourlyWorker("John", 15.0);
        SalariedWorker *worker2 = new SalariedWorker("Jane", 50.0);
        HourlyWorker *worker3 = new HourlyWorker("Jim", 20.0);

        // Add some workers to the company
        c.addWorker(worker1);
        c.addWorker(worker2);
        c.addWorker(worker3);

        TS_ASSERT_EQUALS(c.getWorkers().size(), 3);
    }

    void TestCompanyComputeTotalPay()
    {
        string name = "Acme Corp.";
        Company c(name);

        Worker *worker1 = new HourlyWorker("John", 15.0);
        SalariedWorker *worker2 = new SalariedWorker("Jane", 50.0);
        HourlyWorker *worker3 = new HourlyWorker("Jim", 20.0);

        // Add some workers to the company
        c.addWorker(worker1);
        c.addWorker(worker2);
        c.addWorker(worker3);

        // Compute the total payroll for 40 hours and 45 hours
        TS_ASSERT_EQUALS(c.computeTotalPay(40), 3400.0);
    }

    void TestCompanyGetters()
    {
        string name = "Acme Corp.";
        Company c(name);

        Worker *worker1 = new HourlyWorker("John", 15.0);
        SalariedWorker *worker2 = new SalariedWorker("Jane", 50.0);
        HourlyWorker *worker3 = new HourlyWorker("Jim", 20.0);

        // Add some workers to the company
        c.addWorker(worker1);
        c.addWorker(worker2);
        c.addWorker(worker3);

        TS_ASSERT_EQUALS(c.getName(), "Acme Corp.");
        TS_ASSERT_EQUALS(c.getWorkers().size(), 3);
    }
    void TestCompanyRemoveWorker()
    {
        string name = "Acme Corp.";
        Company c(name);

        Worker *worker1 = new HourlyWorker("John", 15.0);
        SalariedWorker *worker2 = new SalariedWorker("Jane", 50.0);
        HourlyWorker *worker3 = new HourlyWorker("Jim", 20.0);

        // Add some workers to the company
        c.addWorker(worker1);
        c.addWorker(worker2);
        c.addWorker(worker3);

        // Remove a worker from the company
        c.removeWorker(worker1);

        TS_ASSERT_EQUALS(c.getWorkers().size(), 2);
    }

    void TestCompanyOstreamOp()
    {
        string name = "Acme Corp.";
        Company c(name);

        Worker *worker1 = new HourlyWorker("John", 15.0);
        SalariedWorker *worker2 = new SalariedWorker("Jane", 50.0);
        HourlyWorker *worker3 = new HourlyWorker("Jim", 20.0);

        // Add some workers to the company
        c.addWorker(worker1);
        c.addWorker(worker2);
        c.addWorker(worker3);

        std::stringstream ss;
        ss << c;

        TS_ASSERT_EQUALS(ss.str(), "Name: John, Hourly Rate: $15\nName: Jane, Weekly Rate: $50\nName: Jim, Hourly Rate: $20\n");
    }

    void TestCompanyGetNumWorkers()
    {
        string name = "Acme Corp.";
        Company c(name);

        Worker *worker1 = new HourlyWorker("John", 15.0);
        SalariedWorker *worker2 = new SalariedWorker("Jane", 50.0);
        HourlyWorker *worker3 = new HourlyWorker("Jim", 20.0);

        // Add some workers to the company
        c.addWorker(worker1);
        c.addWorker(worker2);
        c.addWorker(worker3);

        TS_ASSERT_EQUALS(c.getNumWorkers(), 3);
    }
    void TestWorkerPrint()
    {
        Worker *worker1 = new Worker("John", 15.0);

        std::stringstream ss;
        ss << *worker1;

        TS_ASSERT_EQUALS(ss.str(), "Name: John, Hourly Rate: $15");
    }
};
