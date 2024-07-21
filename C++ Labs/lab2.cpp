// Aadrij Upadya
// August 29, 2023
// Program P2.6
// Given some input of n meters, we attempt to convert this measure into miles, feet, and inches
#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the number of meters you would like to convert " << endl;
    int meters; // initializing variables
    double miles;
    double feet;
    double inches;
    cin >> meters;
    inches = (meters * 100) / 2.54; // converting to centimeters then inches
    feet = inches / 12;             // dividing by 12 to convert to feet
    miles = feet / 5280;            // dividing by 5280 to convert to miles
    cout << miles;                  // converting to miles
    cout << " miles" << endl;
    cout << feet; // converting to feet
    cout << " feet" << endl;
    cout << inches; // getting inches by multiplying feet by 12
    cout << " inches" << endl;
    return 0;
}