
#include "Triangle.h"
using namespace std;

#include <iostream>

int main()
{
    Triangle triangle1;
    Triangle triangle2;

    // TODO: Read and set base and height for triangle1 (use SetBase() and SetHeight())

    double base, height;

    cin >> base;
    cin >> height;
    triangle1.SetBase(base);
    triangle1.SetHeight(height);

    // TODO: Read and set base and height for triangle2 (use SetBase() and SetHeight())

    cin >> base;
    cin >> height;
    triangle2.SetBase(base);
    triangle2.SetHeight(height);

    cout
        << "Triangle with smaller area:" << endl;

    // TODO: Determine smaller triangle (use GetArea())
    //       and output smaller triangle's info (use PrintInfo())
    if (triangle1.GetArea() < triangle2.GetArea())
    {
        triangle1.PrintInfo();
    }
    else
    {
        triangle2.PrintInfo();
    }

    return 0;
}