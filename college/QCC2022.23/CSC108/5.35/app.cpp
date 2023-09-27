#include <iostream>
#include <string>

using namespace std;

string CoinFlip()
{
    if (rand() % 2 == 0)
    {
        return "Tails";
    }
    else
    {
        return "Heads";
    }
}

int main()
{
    int count;
    cin >> count;
    srand(2);
    for (int i = 0; i < count; i++)
    {
        cout << CoinFlip() << endl;
    }
}