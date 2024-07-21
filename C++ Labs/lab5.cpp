// Aadrij Upadya
// September 14, 2023
// Program P3.23
// Write a program that converts a positive integer into the Roman numeral System
#include <iostream>
using namespace std;
int main()
{
    // Prompt user to provide an integer input
    int number;
    cout << "Enter the number" << endl;
    cin >> number;
    string roman_numeral = "";

    if (number >= 1000)
    {
        // num_times stores the number of times 1000 goes into our number, use 1000 because this is the greatest place we are dealing with
        int num_times = (number / 1000);
        if (num_times == 3)
        {
            roman_numeral += "MMM";
        }
        else if (num_times == 2)
        {
            roman_numeral += "MM";
        }
        else if (num_times == 1)
        {
            roman_numeral += "M";
        }
        // Take mod by the number we are comparing to, 1000 because we want to deal with the remainder now
        number = number % 1000;
    }
    if (number >= 900)
    {
        // 900 has a special rule, as the C has to come before the M instead of having a C and 4 Ms
        roman_numeral += "CM";
        number = number % 900;
    }

    if (number >= 500)
    {
        // If our number is still bigger than 500 after mod 1000, add D
        roman_numeral += "D";
        number = number % 500;
    }

    // use similar logic as the initial control flow with 100, but use 100 instead
    if (number >= 100)
    {
        int num_times = (number / 100);
        if (num_times == 1)
        {
            roman_numeral += "C";
        }
        else if (num_times == 2)
        {
            roman_numeral += "CC";
        }
        else if (num_times == 3)
        {
            roman_numeral += "CCC";
        }
        else if (num_times == 4)
        {
            roman_numeral += "CD";
        }
        number = number % 100;
    }

    // 90 is a special case, so we add a separate if statement for that
    if (number >= 90)
    {
        roman_numeral += "XC";
        number = number % 90;
    }

    if (number >= 50)
    {
        roman_numeral += "L";
        number = number % 50;
    }

    // this is for single digit numbers between 10 and 50, similar logic as with 100 and 1000
    if (number >= 10)
    {
        int num_times = (number / 10);
        if (num_times == 1)
        {
            roman_numeral += "X";
        }
        else if (num_times == 2)
        {
            roman_numeral += "XX";
        }
        else if (num_times == 3)
        {
            roman_numeral += "XXX";
        }
        else if (num_times == 4)
        {
            roman_numeral += "XL";
        }
        number = number % 10;
    }

    // at this point, number should only be a single digit (usually the last digit of the number), so these if statements are for single digit numbers
    if (number == 1)
    {
        roman_numeral += "I";
    }
    else if (number == 2)
    {
        roman_numeral += "II";
    }
    else if (number == 3)
    {
        roman_numeral += "III";
    }
    else if (number == 4)
    {
        roman_numeral += "IV";
    }
    else if (number == 5)
    {
        roman_numeral += "V";
    }
    else if (number == 6)
    {
        roman_numeral += "VI";
    }
    else if (number == 7)
    {
        roman_numeral += "VII";
    }
    else if (number == 8)
    {
        roman_numeral += "VIII";
    }
    else if (number == 9)
    {
        roman_numeral += "IX";
    }

    // outputting the final roman numeral string
    cout << "Number in roman numerals: " << roman_numeral << endl;
}