/*
Electricity Bill Calculator
Problem Statement:
Write a program to calculate electricity bill based on units consumed using conditional statements.

Description:
Conditions:

First 100 units: ₹1.5/unit

Next 100 units: ₹2.5/unit

Beyond 200 units: ₹4/unit

Input Format:
A single integer representing units consumed.

Output Format:
An integer value representing total cost.

Sample Input:
250

Sample Output:
600
*/

#include <iostream>
using namespace std;

int main() {
    int units;
    cout<<"Enter Units : ";
    cin >> units;
    double bill = 0;

    if (units <= 100) {
        bill = units * 1.5;
    } else if (units <= 200) {
        bill = 100 * 1.5 + (units - 100) * 2.5;
    } else {
        bill = 100 * 1.5 + 100 * 2.5 + (units - 200) * 4;
    }

    cout << (int)bill;
    return 0;
}

