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
#include <cctype>
#include <string>

using namespace std;

int main()
{
    string inString, uglyBoolean = "Yes\n";
    cin >> inString;
    for (int i = 0; i < inString.length(); ++i)
    {
        if (isdigit(inString[i]))
        {
            continue;
        }
        else
        {
            uglyBoolean = "No\n";
            break;
        }
    }
    cout << uglyBoolean;
    return 0;
}