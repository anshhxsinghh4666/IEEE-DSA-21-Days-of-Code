/*
Diamond Number Pattern
Problem Statement:
Write a program to print a diamond-shaped pattern using numbers from 1 to n and back.

Description:
Given a number n, print a diamond shape where the numbers increment in the upper half and decrement in the lower half. Each row should be centered.

Input Format:
An integer n (odd)

Output Format:
A diamond pattern with numbers

Sample Input:
5

Sample Output:
  1
 121
12321
 121
  1
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter N : ";
    cin >> n;
    int mid = (n + 1) / 2;
    
    for (int i = 1; i <= n; i++) {
        int row = i <= mid ? i : n - i + 1;
        cout << string(mid - row, ' ');
        for (int j = 1; j <= row; j++) 
            cout << j;
        for (int j = row - 1; j >= 1; j--) 
            cout << j;
        cout << endl;
    }
    
    return 0;
}