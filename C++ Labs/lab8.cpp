// Aadrij Upadya
// October 16, 2023
// Program P5.15
// Write a program that swaps its three arguments to arrange them in sorted error

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
void sort2(int &a, int &b) // function that swaps two integers if first argument is larger than second
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}
void sort3(int &a, int &b, int &c)
{
    while (!(b >= a && b <= c)) // this is the end condition, if b is between a and c
    {
        sort2(b, c); // swap b and c and a and b until the condition is met
        sort2(a, b);
    }
}
int main()
{
    cout << "Enter the numbers" << endl;
    int v, w, x; // Taking in input
    cin >> v;
    cin >> w;
    cin >> x;
    sort3(v, w, x); // Displaying numbers to make sure they are in order
    cout << v << " " << w << " " << x << endl;
}