// Aadrij Upadya
// October 27, 2023
// Program P6.20
// Write a program that constructs magic squares with size n x n

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void create_magic_squares(int n) // n must be odd, repersents length of one side of magic square
{
    if (n % 2 == 0) // Input validation, handling exceptions
    {
        cout << "Please try again with an odd number!" << endl;
    }
    else
    {
        int magic[n][n];    // Initialize a 2D array of dimension n x n that represents the magic square
        int row = n - 1;    // we start from near bottom row
        int column = n / 2; // close to middle column

        for (int i = 0; i < n; i++) // populating array with zeroes
        {
            for (int j = 0; j < n; j++)
            {
                magic[i][j] = 0;
            }
        }

        for (int k = 1; k <= (n * n); k++) // Our magic square has to be filled with numbers from 1 to n^2
        {
            int prerow = row; // storing initial values of row and column to use for later
            int precol = column;

            magic[row][column] = k; // set element at row and column to k
            row++;                  // increment row and column (move down and to right)
            column++;

            if (row == n) // if we reach our boundaries, reset row by equating to 0
            {
                row = 0;
            }
            else if (column == n) // if we reach our boundaries, reset column by equating to 0
            {
                column = 0;
            }

            if (magic[row][column] != 0) // if our value is already populated, set row and column values to previous values
            {
                row = prerow;
                column = precol;
                row--; // decrement row
            }
        }

        for (int i = 0; i < n; i++) // printing contents of array to make sure program works
        {
            for (int j = 0; j < n; j++)
            {
                cout << magic[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{       
    create_magic_squares(5); // calling function with odd int n
}