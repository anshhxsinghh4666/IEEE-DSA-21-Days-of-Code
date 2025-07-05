/*
Month Days Finder
Problem Statement:
Write a program that takes a month (as a number) and a year as input and prints the number of days in that month, considering leap years.

Description:
The program should read the month and year continuously until the user inputs a stop value. You need to handle leap years and invalid inputs.

Input Format:
The first line contains an integer n (number of entries).
The next n lines contain two integers each: the month and the year.
The input stops when the user enters -1 -1.
Output Format:
Print the number of days in the given month for each input.

Sample Input:
2 1900 -1 -1

Sample Output:
28
*/

#include <iostream>
using namespace std;

int main() {
    while (true) {
        int month, year;
        cout << "Enter month and year (or -1 -1 to exit): ";
        cin >> month >> year;

        // Exit condition
        if (month == -1 && year == -1) {
            break;
        }

        // Input validation
        if (cin.fail() || month < 1 || month > 12 || year < 0) {
            cin.clear(); // Clear error flags
            cin.ignore(10000, '\n'); // Ignore bad input
            cout << "Invalid input. Enter numbers (month: 1-12, year >= 0).\n";
            continue;
        }

        int days = 0;

        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                days = 31;
                break;
            case 4: case 6: case 9: case 11:
                days = 30;
                break;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    days = 29;
                } else {
                    days = 28;
                }
                break;
            default:
                // Unreachable due to input validation, but kept for completeness
                cout << "Invalid month.\n";
                continue;
        }

        cout << "Days: " << days << "\n";
    }
    return 0;
}