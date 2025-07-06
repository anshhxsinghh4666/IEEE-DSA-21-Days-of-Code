/*
Hollow Square Star Pattern
Problem Statement:
Write a program to print a hollow square number pattern of given size n.

Description:
The program should accept an integer input n and print a hollow square of size n. The borders should be filled with the digit 1, and the inside of the square should be empty (spaces). The pattern will always have the number 1 on the borders.

Input Format:
An integer n

Output Format:
A hollow square pattern of size n using numbers

Sample Input:
5

Sample Output:
11111
1     1
1     1
1     1
11111
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter N : ";
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n)
                cout << "1";
            else
                cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
