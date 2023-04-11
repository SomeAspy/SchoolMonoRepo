/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: hloi
 *
 * Created on February 7, 2020, 9:32 PM
 */

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

/*
 *
 */

int main(int argc, char **argv)
{

    // create a student object and add a few scores to the student
    // Enter a score
    string name;
    cout << "Enter a student name: " << endl;
    cin >> name;
    cout << name << endl;
    // Use the overload constructor to create a student object with name
    // enter -1 to stop
    Student s1(name);
    double score;
    while (score > 0)
    {
        cout << "Enter a quiz score: " << endl;
        cin >> score;
        cout << score << endl;
        if (score > 0)
        {
            s1.AddQuiz(score);
        }
    }

    cout << "Student name: " << s1.GetName() << endl;
    cout << "Total scores: " << s1.GetTotalScores() << endl;
    cout << "Average scores: " << s1.GetAverageScores() << endl;
    return 0;
}
