/*
    Aiden B.
    See license at head of repository
    Summary: Grade Calculator
    Time Spent: 1h - too much time debugging stupid mistakes (again)
    DOB: 11/23/24
    Output:
    > Enter the name of student 1: Peter
    > Enter test score 1 for Peter: 90
    > Enter test score 2 for Peter: 80
    > Enter test score 3 for Peter: 70
    > Enter test score 4 for Peter: 85
    > Results:
    > Student Name   Dropped Score   Average Score   Grade
    > Peter          70.00           85.00           B
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using std::cin;
using std::cout;
using std::fixed;
using std::left;
using std::setprecision;
using std::setw;
using std::stod;
using std::string;
using std::vector;

// fully customizable! wow!
const int studentCount = 5;
const int gradesPerStudent = 4;

class StudentData
{
public:
    string name;
    vector<double> grades; // I want to modify the length later, hence the vector.
    double droppedGrade;
    double average;
};

char getLetterGrade(double gradeValue)
{
    if (gradeValue >= 90)
    {
        return 'A';
    }
    else if (gradeValue >= 80)
    {
        return 'B';
    }
    else if (gradeValue >= 70)
    {
        return 'C';
    }
    else if (gradeValue >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

double calculateAverageGrade(vector<double> &vec)
{
    double total = 0;
    for (unsigned int i = 0; i < vec.size() - 1; ++i)
    {
        total += vec.at(i);
    }
    return total / (vec.size() - 1); // sans one because removed grade
}

double dropLowestGrade(vector<double> &grades) // from what I understand a vector is already by reference
{
    double lowestGrade = grades.at(1);
    for (unsigned int gradeIndex = 1; gradeIndex < grades.size(); ++gradeIndex)
    {
        if (grades.at(gradeIndex) < lowestGrade)
        {
            lowestGrade = grades.at(gradeIndex);
        }
    }
    for (unsigned int i = 0; i < grades.size() - 1; ++i)
    {
        if (grades.at(i) == lowestGrade)
        {
            grades.erase(grades.begin() + i);
            break;
        }
    }
    return lowestGrade;
}

void printData(StudentData students[studentCount])
{
    cout
        << "Results:\nStudent Name   Dropped Score   Average Score   Grade";
    for (unsigned int i = 0; i < studentCount; ++i)
    {
        cout << "\n"
             << setprecision(2) << fixed << setw(15) << left << students[i].name << setw(16) << students[i].droppedGrade << setw(16) << students[i].average << getLetterGrade(students[i].average);
    }
    cout << "\n";
}

int main()
{
    StudentData students[studentCount]; // StudentData[] creates a 2D array, students[].grades[]
    for (int studentIndex = 0; studentIndex < studentCount; ++studentIndex)
    {
        cout << "Enter the name of student " << studentIndex + 1 << ": ";
        cin >> students[studentIndex].name;
        for (unsigned int studentGradeIndex = 0; studentGradeIndex < gradesPerStudent; ++studentGradeIndex)
        {
            bool badInput = true;
            string input;
            double inputD;

            while (badInput)
            {
                cout << "Enter test score " << studentGradeIndex + 1 << " for " << students[studentIndex].name << ": ";
                cin >> input;
                inputD = stod(input);

                if (inputD >= 0 && inputD <= 100)
                {
                    students[studentIndex].grades.push_back(inputD);
                    badInput = false;
                }
            }
        }
        students[studentIndex].droppedGrade = dropLowestGrade(students[studentIndex].grades);
        students[studentIndex].average = calculateAverageGrade(students[studentIndex].grades);
    }

    printData(students);
}