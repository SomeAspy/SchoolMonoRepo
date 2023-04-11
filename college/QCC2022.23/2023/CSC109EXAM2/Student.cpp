#include "Student.h"
#include <string>

using std::string;

Student::Student()
{
    name = "";
}

Student::Student(string name)
{
    this->name = name;
}

string Student::GetName()
{
    return name;
}

void Student::SetName(string name)
{
    this->name = name;
}

void Student::AddQuiz(double score)
{
    scores.push_back(score);
}

double Student::GetTotalScores()
{
    double total = 0;
    for (unsigned int i = 0; i < scores.size(); i++)
    {
        total += scores[i];
    }
    return total;
}

double Student::GetAverageScores()
{
    return this->GetTotalScores() / scores.size();
}

bool Student::operator<(Student &s)
{
    return this->GetAverageScores() < s.GetAverageScores();
}

bool Student::operator>=(Student &s)
{
    return this->GetAverageScores() >= s.GetAverageScores();
}
