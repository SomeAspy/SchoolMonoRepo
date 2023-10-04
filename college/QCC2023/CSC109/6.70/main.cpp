#include <iostream>
#include <vector>
using namespace std;

/* Define your function here */

int *GetUserValues(const int numValues)
{
    int *numArray = new int[numValues];
    for (int i = 0; i < numValues; ++i)
    {
        int x;
        cin >> x;
        numArray[i] = x;
    }
    return numArray;
}

void OutputIntsLessThanOrEqualToThreshold(int *userValues, int numValues, int upperThreshold)
{
    for (int i = 0; i < numValues; ++i)
    {
        if (userValues[i] <= upperThreshold)
        {
            cout << userValues[i] << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    int *userValues;
    int upperThreshold;
    int numValues;

    cin >> numValues;
    userValues = GetUserValues(numValues); // user cin to read in the user inputs and return a dynamic allocated array

    cin >> upperThreshold;
    OutputIntsLessThanOrEqualToThreshold(userValues, numValues, upperThreshold); // print the dynamic allocated array

    return 0;
}
