/* Aadrij Upadya
March 6th, 2024
C++ GCD/Bezout program, Lab 4
This is meant to write gcd as linear combination of two integers
 */

#include <iostream>
#include <set>
#include <string>
#include <cmath>

using namespace std;

// creating global vectors for remainders, coefficients, factors, so they can be accessed by both functions
vector<int> remainders;
vector<int> coefficients;
vector<int> factors;

/**
 * @brief Bezout function to find u and v such that au + bv = gcd
 * @param a this represents the larger remainder
 * @param b this represents the smaller remainder
 * @param u coefficient of larger number a
 * @param v coefficient of smaller number b
 * @param passing in gcd from euclid function to check base condition
 * @param ptr pointer to iterate backwords through remainder and coefficient vectors to calculate new a, b, u, v
 */
void bezout(int a, int b, int u, int v, int gcd, int ptr)
{

    // special case if numbers are divisible
    if (factors.size() == 1)
    {
        cout << "a and b are: 0 and 1" << endl; // true for all divisible numbers, gcd is just 1 times small number
    }

    // special case if number of remainders is small

    else if (factors.size() == 2)
    {
        cout << "a and b are: " << u << " " << (-1 * coefficients[0]) << endl; // true for all combinations where number of steps is just 1
    }

    // base case is if combination of numbers is equal to gcd when multiplied by original a and original b
    else if (abs(((factors[0] * abs(v)) - ((factors[0] * coefficients[0] + remainders[0]) * abs(u)))) == gcd)
    {
        if ((remainders.size() % 2 == 0))
        {
            cout << "a and b are: " << (-1 * u) << " " << (-1 * v) << endl; // reversing signs if even sized because recursion algorithm doesn't flip signs
        }
        else
        {
            cout << "a and b are: " << u << " " << v << endl; // if odd number, original combination is fine
        }
    }

    else
    {
        // if pointer is negative, we will allow program to access incorrect memory
        if (ptr < 0)
        {
            cout << "error while recursing" << endl;
        }
        else
        {
            int old_u = u; // storing values of u and v that are true initially
            int old_v = v;
            b = a;                                                    // b becomes a, which is now the smaller remainder
            a = (factors[ptr] * coefficients[ptr] + remainders[ptr]); // finding the next remainder
            v = ((abs(old_u)) + (coefficients[ptr] * old_v));         // working algorithm out, u and v can be expressed as this
            u = (-1 * old_v);
            // cout << a << " " << b << " " << u << " " << v  endl;

            bezout(a, b, u, v, gcd, ptr - 1); // recursion algorithm that uses updated values but iterates pointer down to go to next elements
        }
    }
}

/**
 * @brief Function that uses euclidean algorithm to find gcd of two integers
 * @param a this represents the larger of the two given integers
 * @param b this represents the smaller of the two give integers
 */

void gcd(int a, int b)
{
    // if by accident second number is larger, swap both values
    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    // storing initial values for both, as they will change later in program
    int initial_a = a;
    int initial_b = b;

    // while loop that calculates all factors, remainders, coefficients for a and b
    int remainder = a;
    while (remainder != 0)
    {
        int coeff = 0;
        int initial = a;
        // checking how many times b goes into a, storing as coefficient
        while (initial >= b)
        {
            initial = initial - b;
            coeff++;
        }

        // updating values and adding to vectors
        remainder = a - (coeff * b);
        remainders.push_back(remainder);
        factors.push_back((a - (remainder)) / coeff);
        coefficients.push_back(coeff);
        // new values of a and b will be equal to old value of b and remainder
        a = b;
        b = remainder;
    }

    int gcd;
    // special case, where b is factor of a so it will be gcd
    if ((initial_a % initial_b) == 0)
    {
        gcd = initial_b;
    }
    // always second to last element of remainders if size greater than 2, or last element if exactly 2

    else
    {
        gcd = remainders[remainders.size() - 2];
    }
    int ptr = (remainders.size() - 3); // pointer starts from 3rd to last element

    // error handling for special cases, if size is less than 3
    if (remainders.size() == 1)
    {
        ptr = -1;
    }
    else if ((remainders.size() == 2))
    {
        ptr = 0;
    }
    // coefficient is offset by 1 compared to other elements
    int c_ptr = ptr + 1;
    // initial values of a, b, u, v, and ptr
    bezout(factors[ptr], remainders[ptr], 1, coefficients[c_ptr], gcd, ptr);

    // printing our vectors out for readability purposes

    cout << "Remainders: ";
    for (int i = 0; i < remainders.size(); i++)
    {
        cout << remainders[i] << " ";
    }
    cout << endl;

    cout << "Coefficients: ";
    for (int i = 0; i < coefficients.size(); i++)
    {
        cout << coefficients[i] << " ";
    }
    cout << endl;

    cout << "Factors: ";
    for (int i = 0; i < factors.size(); i++)
    {
        cout << factors[i] << " ";
    }
    cout << endl;

    // printing out GCD of (a,b)
    cout << "GCD: " << gcd << endl;
}

int main()
{
    // taking in input from user
    int a;
    cout << "Type the first integer" << endl;
    cin >> a;
    int b;
    cout << "Type the second integer" << endl;
    cin >> b;
    gcd(a, b);
}
