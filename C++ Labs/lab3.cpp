// Aadrij Upadya
// September 1, 2023
// Program P2.18
// Given a string input of a number with a comma, we use string indexing and substrings
#include <iostream>
using namespace std;
int main()
{
    cout << "Enter a number between 1,000 and 999,999 " << endl;

    string number; // initializing variables
    cin >> number; // taking in user input
    const int length = number.length();

    int index = length - 4;                                                         // the comma should be at length - 4
    string new_number = number.substr(0, index) + number.substr(index + 1, length); // create new string that excludes comma

    cout << new_number << endl;
    return 0;
}