/*
Sum of Digits Until Single Digit
Problem Statement:
Write a program to reduce a number to a single-digit sum by continuously summing its digits using loops.

Description:
Repeat summing digits until a single-digit number is obtained.

Input Format:
An integer n

Output Format:
Final single-digit number

Sample Input:
9875

Sample Output:
2
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter Number : ";
    cin >> n;

    while (n >= 10) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }

    cout << n << endl;
    return 0;
}