// Aadrij Upadya
// October 2, 2023
// Program P4.1c
// Write a program that sums all up all powers of 2 from 2^0 to 2^20
#include <iostream>
using namespace std;
int main()
{
    int power_two_sum = 0; // creating a variable to keep track of sum

    for (int i = 0; i <= 20; i++) // for loop from each exponent bound that we want to sum to
    {
        power_two_sum += pow(2, i); // using the power function to sum 2^i
    }

    cout << "Sum of all power of 2 from 0 to 20 " << power_two_sum << endl; // returning the sum back to user

    return 0;
}