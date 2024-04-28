// Copyright (c) 2022 Aiden
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <iostream>
using namespace std;

int main()
{
    int userNum, userNum2;
    cout << "Enter integer:\n";
    cin >> userNum;
    cout << "You entered: " << userNum << endl;
    cout << userNum << " squared is " << userNum * userNum << endl;
    cout << "And " << userNum << " cubed is " << userNum * userNum * userNum << "!!\n";
    cout << "Enter another integer:\n";
    cin >> userNum2;
    cout << userNum << " + " << userNum2 << " is " << userNum + userNum2 << endl;
    cout << userNum << " * " << userNum2 << " is " << userNum * userNum2 << endl;
}