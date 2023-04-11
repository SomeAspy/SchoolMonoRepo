#define CSC109EXAM2_STUDENT_H
#include <vector>
#include <string>

using std::string;
using std::vector;

class Student
{
private:
    string name;
    vector<double> scores;

public:
    Student();
    Student(string name);
    string GetName();
    void SetName(string name);
    void AddQuiz(double score);
    double GetTotalScores();
    double GetAverageScores();
    bool operator<(Student &s);
    bool operator>=(Student &s);
};
