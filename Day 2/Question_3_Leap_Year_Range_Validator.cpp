/*
Leap Year Range Validator
Problem Statement:
Given two years A and B (A < B), list all leap years in that range inclusive.

Description:
Use nested if conditions to validate and determine leap years.

Input Format:
Two integers A and B.

Output Format:
All leap years from A to B (space-separated), or "None"

Sample Input:
2000 2010

Sample Output:
2000 2004 2008
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a, b;
    vector<string> leap_years;
    bool found = false;

    // Input validation
    cout<<"Enter Starting Year : ";
    if (!(cin >> a)) {
        cout << "Invalid input for a" << endl;
        return 1;
    }
    cout<<"Enter Ending Year : ";
    if (!(cin >> b)) {
        cout << "Invalid input for b" << endl;
        return 1;
    }

    // Find leap years
    for (int year = a; year <= b; year++) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            leap_years.push_back(to_string(year));
            found = true;
        }
    }

    // Output results with spaces
    if (found) {
        for (size_t i = 0; i < leap_years.size(); i++) {
            cout << leap_years[i];
            if (i != leap_years.size() - 1) {
                cout << " ";  // Add space between years
            }
        }
        cout << endl;
    } else {
        cout << "None" << endl;
    }

    return 0;
}