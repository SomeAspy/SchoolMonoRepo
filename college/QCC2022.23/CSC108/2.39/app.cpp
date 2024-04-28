// Copyright (c) 2022 Aiden
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int age, weight, bpm, time;

    cin >> age >> weight >> bpm >> time;

    cout << "Calories: " << fixed << setprecision(2) << ((age * 0.2757) + (weight * 0.03295) + (bpm * 1.0781) - 75.4991) * time / 8.368 << " calories\n";
    return 0;
}