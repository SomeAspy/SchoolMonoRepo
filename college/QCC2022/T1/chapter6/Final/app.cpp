#include <iostream>
#include <assert.h>
using namespace std;

// 1. Write a function, accumSum, that takes in an array nums and size of an array as parameters.
// accumSum function updates the array with the accumulated sum for each element in the array as described above.
// The function does not return anything.

void accumSum(int nums[], const int size)
{
    for (int i = 1; i < size; ++i)
    {
        nums[i] += nums[i - 1];
    }
}

// 2. Write a function, printArray, that takes in an array nums and size of an array as parameters.
// printArray function prints out the values of the input array separate with commas.

void printArray(int nums[], const int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << nums[i];
        if (i < size - 1)
        {
            cout << ",";
        }
    }
    cout << endl;
}

int main()
{

    // fill your array with user's input integers.

    int numInts;
    int i;

    // numInts indicates the number of integer values in the array
    // Input begins with number of integers that follow, then list of integers
    cin >> numInts;
    int nums[numInts];

    // TODO: declare an array here.

    for (i = 0; i < numInts; ++i)
    {
        cin >> nums[i];
    }

    // Now call accumSum to calculate the accumulated sum for each element in the array.

    accumSum(nums, numInts);

    // print the array with the accumulated sum for each element in the array.
    // For example, if nums array has 1,2,3,4,5
    // call accumSum to update the array with the accumulated sum
    // then call printArray will print 1,3,6,10,15

    printArray(nums, numInts);

    // write 5 test cases for accumSum on the array.  Do not assume you know the values of the array.
    // you are testing the accumulate values in the array

    int test1[] = {1, 2, 3, 4, 5};
    accumSum(test1, 5);
    assert(test1[0] == 1);
    assert(test1[4] == 15);

    int test2[] = {9999, 9999, 9999, 9999, 9999};
    accumSum(test2, 5);
    assert(test2[0] == 9999);
    assert(test2[4] == 49995);

    int test3[] = {0, 0, 0, 0, 0};
    accumSum(test3, 5);
    assert(test3[0] == 0);
    assert(test3[4] == 0);

    int test4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    accumSum(test4, 10);
    assert(test4[0] == 1);
    assert(test4[9] == 55);

    int test5[] = {-1, 2, -3, 4, -5, 6, -7, 8, -9, 10};
    accumSum(test5, 10);
    assert(test5[0] == -1);
    assert(test5[9] == 5);
}