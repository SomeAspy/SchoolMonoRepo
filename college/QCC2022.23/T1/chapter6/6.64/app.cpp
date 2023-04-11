#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    vector<float> v(5);
    for (size_t i = 0; i < 5; i++)
    {
        cout << "Enter weight " << i + 1 << ":\n";
        cin >> v[i];
    }
    cout << "You entered: ";
    for (size_t i = 0; i < 5; i++)
    {
        cout << fixed << setprecision(2) << v[i] << " ";
    }
    float sum = 0;
    for (size_t i = 0; i < 5; i++)
    {
        sum += v[i];
    }

    float max = v[0];
    for (size_t i = 1; i < 5; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    cout << "\n\nTotal weight: " << fixed << setprecision(2) << sum << endl;
    cout << "Average weight: " << fixed << setprecision(2) << sum / 5 << endl;
    cout << "Max weight: " << fixed << setprecision(2) << max << endl;
}