#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::cin;
using std::cout;
using std::getline;
using std::isspace;
using std::string;
using std::stringstream;
using std::vector;

string
removeSpace(string str)
{
    string outs;
    for (unsigned int i = 0; i < str.length(); ++i)
    {
        if (!isspace(str[i]))
        {
            outs += str[i];
        }
    }
    return outs;
}

int main()
{
    while (true)
    {
        cout << "Enter input string:\n";
        string input, first, last;
        getline(cin, input);
        if (input == "q")
        {
            break;
        }
        stringstream ss(input);
        getline(ss, first, ',');
        getline(ss, last, ',');
        if (last == "")
        {
            cout << "Error: No comma in string.\n\n";
            continue;
        }
        first = removeSpace(first);
        last = removeSpace(last);
        cout << "First word: " << first << "\nSecond word: " << last << "\n\n";
    }
}
