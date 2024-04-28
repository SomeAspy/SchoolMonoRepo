// Copyright (c) 2022 Aiden
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string dirtyGrade;
    cout << "Enter your letter grade: ";
    cin >> dirtyGrade;
    char grade = dirtyGrade[0];
    float score;
    switch (grade)
    {
    case 'A':
        score = 4;
        break;
    case 'B':
        score = 3;
        break;
    case 'C':
        score = 2;
        break;
    case 'D':
        score = 1;
        break;
    default:
        score = 0;
    }
    if (dirtyGrade.length() > 1)
    {
        if (dirtyGrade[0] != 'A' && dirtyGrade[0] != 'F')
        {
            if (dirtyGrade[1] == '+')
            {
                score += 0.3;
            }
            else if (dirtyGrade[1] == '-')
            {
                score -= 0.3;
            }
        }
    }
    cout << "The equivalent number grade is " << score << endl;
    return 0;
}