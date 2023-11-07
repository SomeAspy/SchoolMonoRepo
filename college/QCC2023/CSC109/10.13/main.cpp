#include <iostream>
#include <string>
#include "Cat.h"

using std::cin;
using std::cout;
using std::getline;
using std::string;

int main()
{

    string petName, catName, catBreed;
    int petAge, catAge;

    Pet myPet;
    Cat myCat;

    getline(cin, petName);
    cin >> petAge;
    cin.ignore();
    getline(cin, catName);
    cin >> catAge;
    cin.ignore();
    getline(cin, catBreed);

    // TODO: Create generic pet (using petName, petAge) and then call PrintInfo
    myPet.SetAge(petAge);
    myPet.SetName(petName);
    myCat.SetAge(catAge);
    myCat.SetName(catName);
    myCat.SetBreed(catBreed);
    myPet.PrintInfo();
    myCat.PrintInfo();
    cout << "   Breed: " << myCat.GetBreed() << '\n';

    // TODO: Create cat pet (using catName, catAge, catBreed) and then call PrintInfo

    // TODO: Use GetBreed(), to output the breed of the cat
}
