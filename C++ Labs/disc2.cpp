/* Aadrij Upadya
February 12th, 2024
C++ Relations program, Lab 2
This program is meant to test 2 relations for a set of points (reflexive and symmetry)
 */

#include <iostream>
#include <set>
#include <string>

using namespace std;

/**
 * @brief Checks if set of ordered pairs formed by x and y are reflexive
 * @param x[] array of integers that represents the domain
 * @param y[] array of integers that represents the range
 * @param size reprsents number of ordered pairs and length of arrays x and y
 * @return true if x and y are in relation for all of domain, false if otherwise

 */
bool check_reflexive(int x[], int y[], int size)
{
    vector<int> domain; // creating a vector to store domain (unique elements in x)
    for (int i = 0; i < size; i++)
    {
        bool found = false;
        for (int j = 0; j < domain.size(); j++)
        {
            if (x[i] == domain[j])
            {
                found = true; // checking if element in x is already in domain
            }
        }
        if (!(found))
        {
            domain.push_back(x[i]); // only add if not in domain
        }
    }

    int reflexive_cnt = 0; // keeping count of number of reflexive pairs
    for (int i = 0; i < domain.size(); i++)
    {
        for (int j = 0; j < size; j++) // for each number in domain
        {
            if ((x[j] == domain[i]) && (y[j] == domain[i])) // check if same pair exists in x and y
            {
                reflexive_cnt++; // iterate counter if so
            }
        }
    }
    if (reflexive_cnt - 1 >= domain.size()) // removing duplicate count by subtracting 1
    {
        return true; // return true if number of pairs same as domain
    }

    return false; // false returned by default
}

/**
 * @brief Checks if set of ordered pairs formed by x and y are symmetric
 * @param x[] array of integers that represents the domain
 * @param y[] array of integers that represents the range
 * @param size reprsents number of ordered pairs and length of arrays x and y
 * @return true if for every (x,y), (y,x) exists as well

 */
bool check_symmetric(int x[], int y[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool found = false;

        for (int j = 0; j < size; j++) // nested for loop to check if for each (x,y) there is a (y,x) later in the set
        {
            if ((y[j] == x[i] && x[j] == y[i]))
            {
                found = true; // trigger condition if true
            }
        }
        if (!(found))
        {
            return false; // if we cannot find such a pair, set is not symmetric by definition
        }
    }
    return true; // if false condition hasn't been triggered yet, set is symmetric
}

int main()
{
    // creating 13 points stored as x and y coordinates in array
    int x[] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 6, 3, 6};
    int y[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 3, 6, 6};
    // passing in size of arrays as a separate parameter
    int size = 13;
    // calling functions and printing feedback
    if (check_reflexive(x, y, size))
    {
        cout << "Ordered pairs are reflexive" << endl;
    }
    else
    {
        cout << "Ordered pairs are not reflexive" << endl;
    }

    if (check_symmetric(x, y, size))
    {
        cout << "Ordered pairs are symmetric" << endl;
    }
    else
    {
        cout << "Ordered pairs are not symmetric" << endl;
    }
}