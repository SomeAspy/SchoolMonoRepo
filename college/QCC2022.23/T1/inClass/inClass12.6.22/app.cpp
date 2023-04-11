#include <vector>
#include <iostream>

using namespace std;

int minValue(vector<int> v)
{
    int min = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] < min)
        {
            min = v[i];
        }
    }
    return min;
}

int max2d(vector<vector<int>> v)
{
    int max = v[0][0];
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (v[i][j] > max)
            {
                max = v[i][j];
            }
        }
    }
    return max;
}

int sum2d(vector<vector<int>> v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            sum += v[i][j];
        }
    }
    return sum;
}

float avg2d(vector<vector<int>> v)
{
    return sum2d(v) / (v.size() * v[0].size());
}

int main()
{
    const vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << minValue(v) << endl;
    const vector<vector<int>> v2d = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << max2d(v2d) << endl;
    cout << sum2d(v2d) << endl;
    cout << avg2d(v2d) << endl;
    return 0;
}
