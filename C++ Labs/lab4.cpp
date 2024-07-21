// Aadrij Upadya
// September 14, 2023
// Program P3.18
// Given a certain taxing schedule, compute the amount of tax owed
#include <iostream>
using namespace std;
int main()
{

    char married_status;
    cout << "Enter your married status, S for single and M for married" << endl; // Here we take input for married status as a character
    cin >> married_status;

    int income_amount;
    cout << "Enter your income amount, Do not use commas when you enter" << endl; // Integer input for income
    cin >> income_amount;

    double tax_amount;

    if (married_status == 'S') // If single status, go into one control flow
    {
        if (income_amount > 0 && income_amount <= 8000) // If income between 0 and 8000, we implement a 10% tax rule
        {
            tax_amount = 0.1 * income_amount;
        }
        else if (income_amount > 8000 && income_amount <= 32000) // If income b/w 8000 and 32000,
        {
            tax_amount = ((income_amount - 8000) * 0.15) + 800; // 15% tax on amount over 8000 and an 800 base tax
        }
        else
        {
            tax_amount = ((income_amount - 32000) * 0.25) + 4400; // 25% tax on amount over 32000 and a base 4400 tax
        }
    }
    else if (married_status == 'M') // if person is married, different logic flow
    {
        if (income_amount > 0 && income_amount <= 16000) // if income between 0 and 16000
        {
            tax_amount = 0.1 * income_amount; // simple 10% tax rate
        }
        else if (income_amount > 16000 && income_amount <= 64000) // if income between 16000 and 64000
        {
            tax_amount = ((income_amount - 16000) * 0.15) + 1600; // 15% tax on amount over 16000 and a base 1600 tax
        }
        else
        {
            tax_amount = ((income_amount - 64000) * 0.25) + 8800; // 25% tax on amount over 64000 and a base 8800 tax
        }
    }

    cout << "Amount of Tax Owed (in USD): " << tax_amount << endl; // displaying output to user
}
