#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::getline;
using std::left;
using std::remove_if;
using std::right;
using std::setfill;
using std::setw;
using std::string;
using std::vector;

int main()
{
    string title, h1, h2, dp, name;
    int dpn;
    vector<string> dpStrs;
    vector<int> dpInts;
    cout << "Enter a title for the data:\n";
    getline(cin, title);
    cout << "You entered: " << title << "\n\nEnter the column 1 header:\n";
    getline(cin, h1);
    cout << "You entered: " << h1 << "\n\nEnter the column 2 header:\n";
    getline(cin, h2);
    cout << "You entered: " << h2 << "\n\n";
    while (true)
    {
        cout << "Enter a data point (-1 to stop input):\n";
        getline(cin, dp);
        if (dp == "-1")
        {
            break;
        }
        unsigned int commaCount = 0;
        for (unsigned int i = 0; i < dp.length(); ++i)
        {
            if (dp[i] == ',')
            {
                commaCount++;
            }
        }
        name = dp.substr(dp.find(",") + 1);
        name.erase(remove_if(name.begin(), name.end(), isspace), name.end());
        try
        {
            dpn = stoi(name);
            name = dp.substr(0, dp.find(","));
            cout << "Data string: " << name << "\nData integer: " << dpn << "\n\n";
            dpStrs.push_back(name);
            dpInts.push_back(dpn);
        }
        catch (std::invalid_argument)
        {
            if (commaCount == 0)
            {
                cout << "Error: No comma in string.\n\n";
            }
            else if (commaCount != 1)
            {

                cout << "Error: Too many commas in input.\n\n";
            }
            else
            {
                cout << "Error: Comma not followed by an integer.\n\n";
            }
        }
    }

    cout << '\n'
         << right << setw(33) << title << '\n'
         << left << setw(20) << h1 << '|' << right << setw(23) << h2 << '\n'
         << setw(45) << setfill('-') << '\n'
         << setfill(' ');
    for (unsigned int i = 0; i < dpStrs.size(); ++i)
    {
        cout << left << setw(20) << dpStrs[i] << '|' << right << setw(23) << dpInts[i] << '\n';
    }
    cout << '\n';
    for (unsigned int i = 0; i < dpStrs.size(); ++i)
    {
        cout << right << setw(20) << dpStrs[i] << ' ' << left;
        for (unsigned int ii = 0; ii < dpInts[i]; ++ii)
        {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}