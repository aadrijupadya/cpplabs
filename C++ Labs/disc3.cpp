/* Aadrij Upadya
February 16th, 2024
C++ Relations program, Lab 3
This is meant to replicate insertion sort
 */

#include <iostream>
#include <set>
#include <string>

using namespace std;

/**
 * @brief Sort the given array using insertion sort
 * @param arr[] array of integers that we want to sort
 * @param size reprsents number of elements in arr
 */
void insertion_sort(int arr[], int size)
{
    // outer array from second element to end of array
    for (int i = 1; i < size; i++)
    {
        // temporarily store element at current index for comparison
        int temp = arr[i];
        int j = i - 1;
        // iterate to start from current element until we find an element larger than temp
        while ((j >= 0) && (temp < arr[j]))
        {
            // shift elements to right
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // place current element at whatever value of j that is left from while loop
        arr[j + 1] = temp;
    }
}

/**
 * @brief Display elements of array using space as a separator
 * @param arr[] array of integers that we want to print
 * @param size reprsents number of elements in arr
 */
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // array of integers with 11 elements to test our function
    int arr[11] = {3, 6, 4, 5, 8, 7, 2, 4, 9, 1, 0};
    int size = 11;
    cout << "Array before sorting: ";
    print_array(arr, size);
    insertion_sort(arr, size);
    cout << "Array after sorting: ";
    print_array(arr, size);
}
