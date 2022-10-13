// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    double pi = 3.14159265358979323846; // M_PI does not work???
    double radius1, radius2, radius3, area1, area2, area3;
    cout << "Please enter 3 radii: \n";
    cin >> radius1 >> radius2 >> radius3;
    area1 = pi * radius1 * radius1;
    area2 = pi * radius2 * radius2;
    area3 = pi * radius3 * radius3;
    cout << "area of circles from large to small:\n";
    cout << max(area1, max(area2, area3)) << endl;
    if (area2 > area3)
    {
        cout << min(area2, max(area3, area1)) << endl;
    }
    else if (area3 > area2)
    {
        cout << min(area3, max(area2, area1)) << endl;
    }
    else if (area1 > area2)
    {
        cout << min(area1, max(area2, area3)) << endl;
    }
    else
    {
        cout << area3 << endl;
    }

    cout << min(area1, min(area2, area3)) << endl;

    return 0;
}