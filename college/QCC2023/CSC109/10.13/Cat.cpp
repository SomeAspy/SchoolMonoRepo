// Copyright 2023
#include "Cat.h"
#include <iostream>
#include <string>
using std::string;

void Cat::SetBreed(string userBreed)
{
    catBreed = userBreed;
}

string Cat::GetBreed()
{
    return catBreed;
}
