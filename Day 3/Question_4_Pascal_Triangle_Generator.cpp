/*
Pascal’s Triangle Generator
Problem Statement:
Write a Java program to generate Pascal’s Triangle up to n rows.

Description:
Each number is the sum of the two numbers directly above it.

Input Format:
Integer n

Output Format:
n rows of Pascal’s Triangle

Sample Input:
5

Sample Output:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter Number : ";
    cin >> n;

    vector<vector<int>> triangle(n);

    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    // Printing the triangle
    for (const auto& row : triangle) {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}