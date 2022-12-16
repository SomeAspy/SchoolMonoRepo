// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float height, width, area;
    cout << "Enter the height of the rectangle: ";
    cin >> height;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    area = height * width;

    cout << "The area of a rectangle with height of " << height << " and width of " << width << " is " << area << ".\n";

    cout << "The perimeter of a rectangle with height of " << height << " and width of " << width << " is " << (height + width) * 2 << ".\n";

    cout << "The diagonal of a rectangle with height of " << height << " and width of " << width << " is " << sqrt(height * height + width * width) << ".\n";

    // calculate perimeter and set to variable (follow previous)
    // print message for user about perimeter of rectangle.

    // print message for user about the diagonal of the rectangle.

    return 0;
}
