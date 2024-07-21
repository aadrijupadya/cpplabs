// Aadrij Upadya
// November 2, 2023
// Program P6.27
// Write a program that merges two vectors a and b my alternating their elements

#include <iostream>
#include <cstdlib>
using namespace std;
#include <vector>

vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> nums; // initialize empty vector
    // compare the two vectors sizes to see which one is longer
    int large_length = a.size();
    int small_length = b.size();
    if (b.size() >= large_length)
    {
        large_length = b.size();
        small_length = a.size();
    }
    // max index we need is large_length - 1, so for loop till then
    for (int i = 0; i < large_length; i++)
    {
        if (i < small_length) // while i is still small enough, we can access both array elements
        {
            // alternate with a[i] before b[i]
            nums.push_back(a[i]);
            nums.push_back(b[i]);
        }
        else // if i is smaller than large length but bigger than small length
        {
            if (large_length == a.size()) // if a is the large vector, populate with a[i]
            {
                nums.push_back(a[i]);
            }
            else
            {
                nums.push_back(b[i]); // else, b is larger, so populate with b[i]
            }
        }
    }
    return nums; // return our merged vector
}

int main()
{
    vector<int> a(4);                                           // initialize a test vector of size 4
    cout << "Enter the elements of the first vector: " << endl; // prompt user to populate the first vector
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    vector<int> b(5);
    cout << "Enter the elements of the second vector: " << endl; // prompt user to populate the second vector

    for (int i = 0; i < b.size(); i++) // for loop to populate vector b
    {
        cin >> b[i];
    }
    cout << "Contents of merged vector: " << endl;

    vector<int> merged_vector = merge(a, b);       // call function with vector a and b, store in variable
    for (int i = 0; i < merged_vector.size(); i++) // display merged vector
    {
        cout << merged_vector[i] << " ";
    }
}
