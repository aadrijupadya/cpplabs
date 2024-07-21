/* Aadrij Upadya
March 25th, 2024
Permutation, Combinations Lab - Lab 5
Program is meant to calculate number of permutations given input n
*/

#include <iostream>
#include <set>
#include <string>
#include <cmath>

using namespace std;

/**
 * @brief Recursive function to calculate factorial of a number
 * @param n integer that we want to find factorial of
 * @param b this represents the smaller remainder
 * @return n times previous integer
 */
int fact(int n)
{
    // base case is when n = 1, shouldn't multiply by 0
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1); // continue multiplying recursively
    }
}

/**
 * @brief Swap two elements of a vector given indices of those elements
 * @param e vector that we want to modify
 * @param index_1 first index we want to swap (smaller)
 * @param index_2 second index we want to swap (larger)
 * @return vector<int> that has the swapped elements
 */
vector<int> swap(vector<int> e, int index_1, int index_2)
{
    int temp = e[index_1]; // storing first element temporarily
    e[index_1] = e[index_2];
    e[index_2] = temp; // restoring second index to old element
    return e;
}

/**
 * @brief Print contents of vector out
 * @param e vector that we want to iterate
 */
void println(vector<int> e)
{
    for (int i = 0; i < e.size(); i++)
    {
        cout << e[i];
    }
    cout << endl;
}

/**
 * @brief Print all permutations of given number n
 * @param n will print permutations of vector from 1 to n
 */
void perm(int n)
{
    // elements to store every integer from 1 to n
    vector<int> elements;
    for (int i = 1; i <= n; i++)
    {
        elements.push_back(i);
    }
    // first combination
    println(elements);
    // total number of permutations will be n!
    for (int i = 2; i <= fact(n); i++)
    {

        int m = n - 2;
        // find first decrease in sequence working from right
        while (elements[m] > elements[m + 1])
        {
            m -= 1;
        }
        int k = n - 1;
        // find rightmost element larger than m
        while (elements[m] > elements[k])
        {
            k -= 1;
        }
        // swap elements to get new permutation
        elements = swap(elements, m, k);

        int p = m + 1;
        int q = n - 1;
        // continue swapping until indices meet each other
        while (p < q)
        {
            elements = swap(elements, p, q);

            p = p + 1;
            q = q - 1;
        }
        // print new permutation
        println(elements);
    }
}

int main()
{
    // testing permutation function
    perm(4);
}