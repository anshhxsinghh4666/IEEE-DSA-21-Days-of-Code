/*
Reverse Floyd’s Triangle
Problem Statement:
Write a program that prints Floyd’s triangle in reverse.

Description:
Given n rows, print the Floyd’s triangle from bottom to top using numbers in reverse order.

Input Format:
Integer n

Output Format:
Reversed Floyd’s triangle

Sample Input:
3

Sample Output:
4 5 6
2 3
1
*/


#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter Number : ";
    cin >> n;
    int total = n * (n + 1) / 2;
    
    for (int i = n; i >= 1; i--) {
        int start = total - i + 1;
        for (int j = 0; j < i; j++)
            cout << (start + j) << " ";
        total -= i;
        cout << endl;
    }
    
    return 0;
}