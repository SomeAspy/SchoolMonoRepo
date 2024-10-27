/*
    Aiden B.
    See license at head of repository
    Summary: File I/O
    Time spent: 20m
    DOB: 10/27/24
    Output:
    > For how many numbers do you want to enter? 5
    >
    > Write the data to Numbers.txt file
    > Enter the number 1: 12
    > Enter the number 2: 34
    > Enter the number 3: 45
    > Enter the number 4: 61
    > Enter the number 5: 22
    > Data written to Numbers.txt
    > -----The End for entering dats---------
    >
    > Enter the filename: Numbers.txt
    >
    > The data from the Numbers.txt
    > 12
    > 34
    > 45
    > 61
    > 22
    >
    > Number of numbers: 5
    > Sum of the numbers: 174.00
    > Average of the numbers: 34.80
    Notes:
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::fixed;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::setprecision;
using std::stof;
using std::string;

int main()
{
    cout << "For how many numbers do you want to enter? ";
    int count = -1;
    cin >> count;
    cout << "\nWrite the data to Numbers.txt file\n";
    ofstream savedNumbers("Numbers.txt");
    for (int i = 0; i < count; ++i)
    {
        int value = -1;
        cout << "Enter the number " << i + 1 << ": ";
        cin >> value;
        savedNumbers << value << '\n';
    }

    savedNumbers.close();
    cout << "Data written to Numbers.txt\n-----The End for entering dats---------\n\n";
    while (true)
    {
        cout << "Enter the filename: ";
        string fileName;
        cin.ignore();
        cin >> fileName;
        ifstream readData(fileName);
        if (readData.fail())
        {
            cout << "[ERROR]: I/O error";
            readData.close();
            continue;
        }
        cout << "\nThe data from the " << fileName << '\n';
        string fileData;
        float counter = 0, total = 0;
        while (getline(readData, fileData))
        {
            cout << fileData << '\n';
            total += stof(fileData);
            ++counter;
        }
        cout << "\nNumber of numbers: " << counter << fixed << setprecision(2) << "\nSum of the numbers: " << total << "\nAverage of the numbers: " << total / count << '\n';
        break;
    }
}