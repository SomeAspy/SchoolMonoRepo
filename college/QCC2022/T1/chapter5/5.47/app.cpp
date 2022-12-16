#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

// Type your code here

/*
  1.  Write a function to convert a single integer digit to a char DigitToChar.
  Make sure you name your function as DigitToChar.  The function takes
  a single-digit integer number and returns a character of the digit.
  See an ASCII table for the digit character values.
 */

char DigitToChar(int digit)
{
    return digit + '0';
}

/*
  2. Write a function integerWithCommas that takes an integer, and returns a string
  representation of that number with commas appropriately inserted. If the input is 145020,
  the function returns a string "145,020".  You must use DigitToChar in this function
  in order to get full credit for this problem.  Incorrect use of the DigitToChar function
  will result in a 50% or more deduction from this function.  You will get zero credit if
  you don't use DigitToChar in this function.
*/

string integerWithCommas(int number)
{
    string result = "";
    int digitCount = 0;
    while (number > 0)
    {
        result = DigitToChar(number % 10) + result;
        number /= 10;
        digitCount++;
        if (digitCount % 3 == 0 && number > 0)
        {
            result = "," + result;
        }
    }
    if (result == "")
    {
        result = "0";
    }
    return result;
}

/*
   3. Write five unit test cases for DigitToChar function (10 points)
   4. Write five unit test cases for integerWithComma function (10 points)
*/

int main()
{
    int userNum;

    cin >> userNum; // read in a number

    // Call integerWithCommas with userNum;  returns a string representation of that userNum with commas
    // use cout to print out the string
    cout << integerWithCommas(userNum) << endl;

    // write your test cases in below.
    // 5 test cases for DigitToChar
    // 5 test cases for integerWithCommas
    assert(DigitToChar(0) == '0');
    assert(DigitToChar(1) == '1');
    assert(DigitToChar(2) == '2');
    assert(DigitToChar(3) == '3');
    assert(DigitToChar(4) == '4');

    assert(integerWithCommas(0) == "0");
    assert(integerWithCommas(1) == "1");
    assert(integerWithCommas(12) == "12");
    assert(integerWithCommas(123) == "123");
    assert(integerWithCommas(1234) == "1,234");
    return 0;
}