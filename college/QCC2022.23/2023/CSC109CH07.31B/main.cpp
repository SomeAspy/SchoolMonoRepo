#include <iostream>
#include "Triangle.h"
using namespace std;

int main(int argc, const char *argv[])
{
    Triangle triangle1;
    Triangle triangle2;

    // TODO: Read and set base and height for triangle1 (use SetBase() and SetHeight())
    double base;
    double height;
    cin >> base;
    cin >> height;
    triangle1.SetBase(base);
    triangle1.SetHeight(height);

    // TODO: Read and set base and height for triangle2 (use SetBase() and SetHeight())
    cin >> base;
    cin >> height;
    triangle2.SetBase(base);
    triangle2.SetHeight(height);
    // TODO: Determine larger triangle (use GetArea())
    cout << "Triangle with smaller area:" << endl;
    if (triangle1.GetArea() < triangle2.GetArea())
    {
        triangle1.PrintInfo();
    }
    else
    {
        triangle2.PrintInfo();
    }

    // TODO: Output larger triangle's info (use PrintInfo())

    return 0;
}