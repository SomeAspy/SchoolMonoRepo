#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::getline;
using std::remove_if;
using std::string;

int main()
{
    string userInput, first, second;
    while (true)
    {
        while (true)
        {
            cout << "Enter input string:\n";
            getline(cin, userInput);
            if (userInput == "q")
            {
                return 0;
            }
            if (userInput.find(",") != string::npos)
            {
                break;
            }
            cout << "Error: No comma in string.\n\n";
        }
        userInput.erase(remove_if(userInput.begin(), userInput.end(), isspace), userInput.end());
        first = userInput.substr(0, userInput.find(","));
        second = userInput.substr(userInput.find(",") + 1);
        cout << "First word: " << first << "\nSecond word: " << second << "\n\n";
    }
    return 0;
}