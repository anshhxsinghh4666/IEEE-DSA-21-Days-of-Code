/* 
Prime Number Range
Problem Statement:
Write a program using a loop to print all prime numbers between two numbers m and n (inclusive).

Description:
Use nested loops to check each number between m and n for primality and print the result.

Input Format:
Two integers m and n

Output Format:
List of prime numbers in the range, space-separated

Sample Input:
10 20

Sample Output:
11 13 17 19
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m, n;
    cout << "Enter Starting Value : ";
    cin >> m;
    cout << "Enter Endng Value : ";
    cin >> n;

    for (int i = m; i <= n; ++i) {
        if (i <= 1) continue;
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            cout << i << " ";
    }

    return 0;
}