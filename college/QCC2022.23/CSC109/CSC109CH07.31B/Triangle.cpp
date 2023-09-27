// Copyright 2023
#include "Triangle.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::fixed;
using std::round;
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
    return (base * height) / 2;
}

void Triangle::PrintInfo() const
{
    cout << fixed << setprecision(2);
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
    cout << "Area: " << round(GetArea() * 100.0f) / 100.0f << endl;
}

// define CalculateArea()

void Triangle::CalculateArea()
{
    area = (base * height) / 2;
}
