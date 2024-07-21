/* Aadrij Upadya
January 12th, 2024
C++ Sets program, Lab 1
This program has various functions for sets like union, subset, and difference
 */

#include <iostream>
#include <set>
#include <string>

using namespace std;

typedef set<int> int_set; // creating a keyword for ease of use later

/**
 * @brief Lists the elements in a set;
 *
 * @param list_set Set that user wants to be displayed
 */
void list_elements(int_set list_set)
{
    int_set::iterator iter;  // create an iterator to navigate set
    iter = list_set.begin(); // assign iterator to start of set
    cout << *iter;
    iter++;
    while (iter != list_set.end())
    {
        cout << ", " << *iter; // print each element by dereferencing iterator and adding separator
        iter++;
    }
    cout << endl;
}

/**
 * @brief Combines setA and setB, while removing duplicate elements
 *
 * @param setA First set of integers to be combined with setB
 * @param setB Second set of integers to be combined with setA
 * @return unionized_set that has elements from both A and B, removing duplicates
 */
int_set set_union(int_set setA, int_set setB)
{
    int_set ::iterator A_iter; // create an iterator to navigate each sets
    int_set ::iterator B_iter;
    int_set unionized_set; // empty set which will be added to later
    A_iter = setA.begin();
    // while loop to add everything from set A into unionized set
    while (A_iter != setA.end())
    {
        unionized_set.insert(*A_iter); // access element by dereferencing iterator and insertting into set
        A_iter++;
    }

    // while loop to add everything from set B into unionized set
    B_iter = setB.begin();
    while (B_iter != setB.end())
    {
        unionized_set.insert(*B_iter);
        B_iter++;
    }
    // return unionized_set, which already takes into account duplicates
    return unionized_set;
}

/**
 * @brief Returns elements of setA that aren't in setB
 *
 * @param setA Set that contains all integers of setA
 * @param setB Set that contains all integers of setB
 * @return unionized_set that has elements from both A and B, removing duplicates
 */
int_set set_difference(int_set setA, int_set setB)
{
    int_set ::iterator A_iter; // create an iterator to navigate each sets
    int_set ::iterator B_iter;
    int_set difference_set; // create an empty set which will have our difference
    A_iter = setA.begin();  // assign iterator to start of set A

    // traversing through setA
    while (A_iter != setA.end())
    {
        if (setB.find(*A_iter) == setB.end()) // check if element at A_iter is NOT in setB
        {
            difference_set.insert(*A_iter); // if so, add to our difference set
        }
        A_iter++; // increment iterator to move on to next element
    }
    return difference_set; // return our difference set
}

/**
 * @brief Returns whether setA is a subset of setB or if setB is a subset of setA
 *
 * @param setA Set that contains all integers of setA
 * @param setB Set that contains all integers of setB
 * @return boolean that returns true if all elements of one set are in other, false if otherwise
 */
bool is_subset(int_set setA, int_set setB)
{
    int_set ::iterator A_iter; // create an iterator to navigate each sets
    int_set ::iterator B_iter;
    A_iter = setA.begin(); // assign iterator to start of both sets
    B_iter = setB.begin();
    if (setA.size() <= setB.size()) // compare sizes to make sure we are traversing the right set
    {
        // if setA size less than or equal to setB size
        while (A_iter != setA.end()) // traverse through setA until we reach end
        {
            if (setB.find(*A_iter) == setB.end()) // If unable to find element in setB, return false
            {
                return false;
            }
            A_iter++; // Otherwise, iterate to next element
        }
        return true;
    }
    else
    { // if setB size less than setA size

        while (B_iter != setB.end()) // traverse through setA until we reach end
        {
            {
                if (setA.find(*B_iter) == setA.end()) // If unable to find setB element in setA, return false
                {
                    return false;
                }
                B_iter++; // Otherwise, iterate to next element
            }
            return true;
        }
    }
    return false; // By default return false
}

int main()
{
    // variables to use later
    int_set ::iterator iter;
    int_set set_of_ints_A;

    // populating our sets
    // set_of_ints_A.insert(1);
    set_of_ints_A.insert(2);
    set_of_ints_A.insert(3);
    cout << "Set A: ";
    list_elements(set_of_ints_A);

    int_set set_of_ints_B;
    set_of_ints_B.insert(2);
    set_of_ints_B.insert(3);
    set_of_ints_B.insert(4);
    set_of_ints_B.insert(5);
    cout << "Set B: ";
    list_elements(set_of_ints_B);

    // testing each of our functions
    int_set unionized_set = set_union(set_of_ints_A, set_of_ints_B);
    cout << "A Union B: ";
    list_elements(unionized_set);

    int_set difference_set = set_difference(set_of_ints_A, set_of_ints_B);
    cout << "A - B: ";
    list_elements(difference_set);

    if (is_subset(set_of_ints_A, set_of_ints_B))
    {
        cout << "Set A is a subset of Set B" << endl;
    }
    else
    {
        cout << "Set A is not a subset of Set B" << endl;
    }
}