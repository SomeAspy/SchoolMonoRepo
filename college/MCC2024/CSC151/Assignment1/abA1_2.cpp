/*
    Aiden B.
    See license at head of repository
    Summary: Determines what ingredients are needed to make x cookies
    Time Spent: 10m
    DOB: 9/15/24
    output:
    > How many cookies do you want to bake? (input 20)
    >
    > To make 20 cookies, you should use
    > 0.625 cups of sugar, 0.416667 cups of butter, and 1.14583 cups of flour.
*/

#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int cookies;
    cout << "How many cookies do you want to bake? ";
    cin >> cookies;

    // I could do the math so it isn't done on-the-fly (first 2 division), but eh.

    float sugar = (1.5 / 48) * cookies;
    float butter = (1.0 / 48) * cookies;
    float flour = (2.75 / 48) * cookies;

    cout
        << "\nTo make " << cookies << " cookies, you should use\n"
        << sugar << " cups of sugar, " << butter << " cups of butter, and " << flour << " cups of flour.\n";

    return 0;
}