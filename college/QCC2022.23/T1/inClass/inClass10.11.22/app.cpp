// Copyright (c) 2022 Aiden Baker
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string email, userName, domainName, TLD;
    cin >> email;

    int emailLength = email.length();

    int atSymbol = email.find("@");
    int dot = email.find(".");

    userName = email.substr(0, atSymbol);
    domainName = email.substr(atSymbol + 1, atSymbol - dot - 1);
    TLD = email.substr(dot + 1);
    cout << "Username: " << userName << endl;
    cout << "Domain: " << domainName << endl;
    cout << "TLD: " << TLD << endl;
    return 0;
}