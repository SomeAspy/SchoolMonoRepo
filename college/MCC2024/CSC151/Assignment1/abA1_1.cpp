/*
    Aiden B.
    See license at head of repository
    Summary: Determines how much paint would be needed for a double sided fence with 2 coats 6x100 ft (no inputs)
    Time Spent: 13m
    DOB: 9/15/24
    output:
    > 7.05882 gallons of paint are needed to paint
    > 2 coats on each side of a 100 x 6 foot fence.
*/

#include <iostream>
#include <iomanip>

using std::cout;
using std::fixed;
using std::setprecision;

int main()
{
    float reqPaint = (2 * 2 * 6 * 100) / 340.0; // 2x side 2x coat 6h*100l / paint coverage

    cout << fixed << setprecision(5) << reqPaint << " gallons of paint are needed to paint\n2 coats on each side of a 100 x 6 foot fence.\n";
    return 0;
}