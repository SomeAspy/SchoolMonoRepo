// Copyright (C) 2022 Aiden Baker
//
// This file is part of SchoolMonoRepo.
//
// SchoolMonoRepo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SchoolMonoRepo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SchoolMonoRepo.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    bool keepAlive = true;
    int maxNum = 0, sum;
    vector<int> numbers;
    while (keepAlive)
    {
        int inNum;
        cin >> inNum;
        if (inNum < 0)
        {
            keepAlive = false;
            break;
        }
        maxNum = max(maxNum, inNum);
        numbers.push_back(inNum);
        sum = 0;
        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            sum += numbers[i];
        }
    }
    cout << maxNum << ' ' << fixed << setprecision(2) << sum * 1.0 / numbers.size() << endl;

    return 0;
}