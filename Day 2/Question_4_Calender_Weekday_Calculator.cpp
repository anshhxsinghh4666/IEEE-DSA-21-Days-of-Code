/* 
Calendar Weekday Calculator
Problem Statement:
Write a program that takes a date (dd mm yyyy) and determines the day of the week it falls on (Monday to Sunday).

Description:
Use Zeller’s Congruence or equivalent logic using conditional statements.

Input Format:
Three integers: day month year

Output Format:
Day of the week (e.g., Tuesday)

Sample Input:
15 08 2023

Sample Output:
Tuesday
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getWeekDay(int d, int m, int y) {
    if (m < 3) {
        m += 12;
        y--;
    }
    int k = y % 100;
    int j = y / 100;
    int f = d + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    int day = f % 7;
    
    vector<string> days = {"Saturday", "Sunday", "Monday", "Tuesday",
                          "Wednesday", "Thursday", "Friday"};
    return days[day];
}

int main() {
    int d, m, y;
    
    // Input validation
    if (!(cin >> d >> m >> y)) {
        cerr << "Invalid input. Please enter three integers: day month year" << endl;
        return 1;
    }
    
    // Optional: Add date validation here
    // if (!isValidDate(d, m, y)) { ... }
    
    cout << getWeekDay(d, m, y) << endl;
    return 0;
}