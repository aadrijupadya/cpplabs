// Aadrij Upadya
// November 16, 2023
// Program P7.2
// Write a program that replaces the value to which p points with x if x is greater

#include <iostream>
#include <cstdlib>
using namespace std;

double replace_if_greater(double *p, double x) // take in pointer and double
{
    double old_value = *p; // store old value that is pointed to
    if (x > *p)            // compare x and pointer value
    {
        p = &x; // if greater, assign pointer to new reference
    }
    return old_value; // returning old_value
}

int main()
{
    double *pointer;                // initializing new pointer
    double p = 7;                   // initialize new double
    pointer = &p;                   // assign pointer to p
    double x = 10;                  // double to compare with
    replace_if_greater(pointer, x); // calling function
}