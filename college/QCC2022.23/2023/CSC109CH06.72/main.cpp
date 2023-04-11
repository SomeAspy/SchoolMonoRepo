#include <iostream>
#include <string>
#include <sstream> // don't remove this line; use for ostringstream
#include <iomanip> // use std::setw to set the width for each number
#include "TwoDArray.h"

using namespace std;

int main()
{

    // I think this is what I'm supposed to do, the program doesn't seem to get input from ZyBooks...

    double printArray[6][7] =
        {
            {11, 2, 3, 4, 5, 6, 7},
            {10, 9, 8, 7, 6, 5, 4},
            {12, 11, 11, 11, 11, 31, 11},
            {5, 5, 5, 5, 5, 5, 5},
            {12, 3, 4, 9, 8, 7, 6},
            {12, 3, 4, 9, 8, 7, 6}};

    std::cout << to_string(*printArray, 6, 7) << std::endl;
}
