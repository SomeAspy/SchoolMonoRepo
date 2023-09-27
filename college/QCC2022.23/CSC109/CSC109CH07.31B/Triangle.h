// Copyright 2023
#ifndef CSC109CH07_31B_TRIANGLE_H
#define CSC109CH07_31B_TRIANGLE_H

#include <string>

class Triangle
{
private:
    double base;
    double height;
    double area;

public:
    void SetBase(double userBase);     // mutator
    void SetHeight(double userHeight); // mutator
    double GetArea() const;            // accessor
    void CalculateArea();              // mutator
    void PrintInfo() const;            // accessor
};

#endif // CSC109CH07_31B_TRIANGLE_H
