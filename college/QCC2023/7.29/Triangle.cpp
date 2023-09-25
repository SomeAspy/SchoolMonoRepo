// Copyright 2023
#include "Triangle.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

void Triangle::SetBase(double userBase)
{
    base = userBase;
}

void Triangle::SetHeight(double userHeight)
{
    height = userHeight;
}

double Triangle::GetArea() const
{
    return 0.5 * base * height;
}

void Triangle::PrintInfo() const
{
    cout << fixed << setprecision(2);
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
    cout << "Area: " << GetArea() << endl;
}
