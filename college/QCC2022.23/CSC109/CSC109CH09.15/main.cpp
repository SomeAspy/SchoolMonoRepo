#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using std::cin;
using std::cout;
using std::getline;
using std::left;
using std::right;
using std::setw;
using std::string;
using std::stringstream;
using std::vector;

void printRow(string str, int i)
{
    cout << left << setw(20) << str << '|' << right << setw(23) << i;
}
void printRow(string str, string i)
{
    cout << left << setw(20) << str << '|' << right << setw(23) << i;
}

void printHistogram(vector<int> ints, vector<string> strs, unsigned int i)
{
    cout << right << setw(20) << strs[i];
    cout << ' ';
    for (int j = 0; j < ints[i]; ++j)
    {
        cout << '*';
    }
    cout << '\n';
}

int main()
{
    string title, h1, h2;
    cout << "Enter a title for the data:\n";
    getline(cin, title);
    cout << "You entered: " << title << "\n\n";

    cout << "Enter the column 1 header:\n";
    getline(cin, h1);
    cout << "You entered: " << h1 << "\n\n";

    cout << "Enter the column 2 header:\n";
    getline(cin, h2);
    cout << "You entered: " << h2 << "\n\n";

    vector<int> count;
    vector<string> names;

    while (true)
    {
        string DS, DT, DE;
        cout << "Enter a data point (-1 to stop input):\n";
        getline(cin, DT);
        if (DT == "-1")
        {
            break;
        }
        stringstream SS(DT);
        DT = "NULL";
        getline(SS, DS, ',');
        getline(SS, DT, ',');
        getline(SS, DE, ',');
        if (DT == "NULL")
        {
            cout << "Error: No comma in string.\n\n";
            continue;
        }
        if (DE != "")
        {
            cout << "Error: Too many commas in input.\n\n";
            continue;
        }
        // below is a mess because I couldn't get this to work with catch()
        stringstream SS2(DT);
        int DI;
        SS2 >> DI;
        if (DI == 0) // if the user enters 0 we are fucked
        {
            cout << "Error: Comma not followed by an integer.\n\n";
            continue;
        }
        cout << "Data string: " << DS;
        cout << "\nData integer: " << DI << "\n\n";
        count.push_back(DI);
        names.push_back(DS);
    }
    cout << '\n';
    cout << right << setw(33) << "Number of Novels Authored";
    cout << '\n';
    printRow("Author name", "Number of novels");
    cout << "\n--------------------------------------------\n";
    for (unsigned int i = 0; i < names.size(); ++i)
    {
        printRow(names[i], count[i]);
        cout << '\n';
    }
    cout << '\n';
    for (unsigned int i = 0; i < names.size(); ++i)
    {
        printHistogram(count, names, i);
    }
}
