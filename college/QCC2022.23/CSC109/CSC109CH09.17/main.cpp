#include "Number.h"
#include <iostream>
using namespace std;

int main()
{
    int input;
    cin >> input;

    Number num = Number(input);
    cout << "The value is " << num << endl;

    return 0;
}
