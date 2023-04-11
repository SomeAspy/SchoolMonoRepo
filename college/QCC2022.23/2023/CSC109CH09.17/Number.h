// Copyright 2023
#ifndef NUMBERH
#define NUMBERH

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Number
{
public:
    Number(int);
    void SetNum(int);
    int GetNum();
    // Declared as a friend function to give operator<< private member access
    friend ostream &operator<<(ostream &out, const Number &n);

private:
    int num;
};

#endif
