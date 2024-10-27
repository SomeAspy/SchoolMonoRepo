/*
    Aiden B.
    See license at head of repository
    Summary: Geometry Calculator
    Time Spent: 30m
    DOB: 10/16/24
    Output:
    > Geometry Calculator
    >
    > 1. Calculate the Area of a Circle
    > 2. Calculate the Area of a Rectangle
    > 3. Calculate the Area of a Triangle
    > 4. Quit
    >
    > Enter your choice (1-4):
    > {Further output will vary}
    Notes: I totally over-engineered this, but whatever. I like modularity.
    Known bugs:
        - Entering a letter as input will cause the program to infinitely loop without exit. Seems outside the scope of this assignment though.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::fixed;
using std::pow;
using std::setprecision;
using std::string;

/**
 * @brief alerts the user that the value is less than zero
 *
 * @param num: Number to check
 * @param valueName: What cannot be less than zero
 *
 * @throws `-1` if value is less than zero
 */
void lessThanZeroAlert(const float num, const string valueName)
{
    if (num < 0)
    {
        cout << "The " << valueName << " can not be less than zero.\n\n";
        throw(-1);
    }
}

/**
 * @brief Returns the circle's area, given user input of radius
 *
 * @returns Area of the circle
 */
float calculateAreaCircle()
{
    const float pi = 3.14159;
    float radius = -1;
    cout << "Enter the circle's radius: ";
    cin >> radius;
    lessThanZeroAlert(radius, "radius");
    return pow(radius, 2) * pi;
}

/**
 * @brief calculate the area of a generic shape
 *
 * @param shapeName: The name of the shape to use when requesting input
 *
 * @return Area calculated
 */
float calculateAreaGenericShape(const string shapeName)
{
    float height, width = -1;
    cout << "Enter the " << shapeName << "'s height: ";
    cin >> height;
    lessThanZeroAlert(height, "height");
    cout << "Enter the " << shapeName << "'s width: ";
    cin >> width;
    lessThanZeroAlert(width, "width");
    return height * width;
}

int main()
{
    int input = -1;
    while (true)
    {
        try
        {
            cout << "Geometry Calculator\n\n1. Calculate the Area of a Circle\n2. Calculate the Area of a Rectangle\n3. Calculate the Area of a Triangle\n4. Quit\n\nEnter your choice (1-4): ";
            float area = -1;

            cin >> input;
            cout << "\n\n"
                 << fixed << setprecision(2);

            switch (input)
            {
            case 1:
                area = calculateAreaCircle();
                cout << "The area is " << area << "\n\n";
                break;
            case 2:
                area = calculateAreaGenericShape("rectangle");
                cout << "The area is " << area << "\n\n";
                break;
            case 3:
                area = calculateAreaGenericShape("triangle");
                cout << "The area is " << area * .5 << "\n\n";
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid option\n\n";
            }
        }
        catch (int x)
        {
            // User entered something less than zero, ignore it and start over
        }
    }
}