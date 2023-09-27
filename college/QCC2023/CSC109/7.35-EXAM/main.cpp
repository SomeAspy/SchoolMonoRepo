// Copyright 2023

#include <iostream>
#include "TimerHrMin.h"
using std::cout;

// Stuff ZyBooks needs because they are stupid:
using std::endl;

// create a class TimerHrMin t3 object
// create a class TimerHrMin t1 object with hour=9 and minute=30
// create a class TimerHrMin t2 object with hour=13 and minute=5
// if (t2 >=t1) // test overloading compare >= operator
//    t3 = t2 - t1;  // test overloading subtract - operator
// else
//    t3 = t1 - t2;  // test overloading subtract - operator
// output:
// t3.hour == 3
// t3.minute = 35

// create a class TimerHrMin t1 object with hour=9 and minute=5
// create a class TimerHrMin t2 object with hour=13 and minute=30
// output:
// t3.hour == 4
// t3.minute = 25

// create a class TimerHrMin t1 object with hour=9 and minute=30
// create a class TimerHrMin t2 object with hour=13 and minute=30
// output:
// t3.hour == 4
// t3.minute = 0

int main()
{
    TimerHrMin x1(9, 30), x2(13, 5), x3, y1(9, 5), y2(13, 30), y3, z1(9, 30), z2(13, 30), z3;

    if (x2 >= x1)
    {
        x3 = x2 - x1;
    }
    else
    {
        x3 = x1 - x2;
    }

    cout << "T1: ";
    x1.Print(true);
    cout << "T2: ";
    x2.Print(true);
    cout << "T3: ";
    x3.Print(false);
    cout << '\n';

    y3 = y2 - y1;

    cout << "T1: ";
    y1.Print(true);
    cout << "T2: ";
    y2.Print(true);
    cout << "T3: ";
    y3.Print(false);
    cout << '\n';

    z3 = z2 - z1;

    cout << "T1: ";
    z1.Print(true);
    cout << "T2: ";
    z2.Print(true);
    cout << "T3: ";
    z3.Print(false);

    return 0;
}
