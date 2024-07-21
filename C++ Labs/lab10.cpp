// Aadrij Upadya
// October 27, 2023
// Program P6.2c
// Write a program that replaces all even elements of an array with 0

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
void replace_even_0(int test[])
{
    for (int i = 0; i < 6; i++) // iterating through array
    {
        if (test[i] % 2 == 0) // if element is even, replace with 0
        {
            test[i] = 0;
        }
    }
}
int main()
{
    int test[] = {1, 2, 3, 4, 5, 6}; // initializing an array to test program
    cout << "Array before replacement: ";
    for (int i = 0; i < 6; i++) // printing contents of array before the function call
    {
        cout << test[i] << " ";
    }
    replace_even_0(test);
    cout << endl;
    cout << "Array after replacement: ";
    for (int i = 0; i < 6; i++) // printing contents of array after the function call
    {
        cout << test[i] << " ";
    }
}