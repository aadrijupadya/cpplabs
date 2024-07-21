// Aadrij Upadya
// October 17, 2023
// Program P5.28
// Write a program that checks if a given string is a palindrome

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
bool is_palindrome(string str)
{
    // have two base cases depending on if string is even or odd
    if (str.length() == 1) // if we return to a final character, return truw
    {
        return true;
    }
    else if (str.length() == 2) // if even, we have 2 characters left
    {
        if (str[0] == str[1]) // check if both characters are same if 2 left
        {
            return true;
        }
        return false; // if not, its not a palindrome
    }
    else if (str[0] == str[str.length() - 1]) // compare first and last characters
    {
        return is_palindrome(str.substr(1, str.length() - 2)); // recursive call without first and last characters
    }
    return false; // default case is to return false
}
int main()
{
    cout << "Enter string you want to check" << endl; // taking in user input
    string input_string;
    cin >> input_string;
    cout << "Is input string a palindrome? " << is_palindrome(input_string) << endl; // returning function output
}