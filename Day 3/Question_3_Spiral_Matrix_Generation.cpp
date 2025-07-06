/*
Spiral Matrix Generation
Problem Statement:
Write a program that prints an n x n matrix filled with numbers from 1 to n² in a clockwise spiral pattern.

Description:
Use nested loops and index manipulation to generate numbers in a spiral form starting from top-left and moving clockwise.

Input Format:
An integer n (n ≥ 1)

Output Format:
Spiral matrix as n lines of n space-separated integers

Sample Input:
3

Sample Output:
1 2 3
8 9 4
7 6 5
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter Number : ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int value = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (value <= n * n) {
        // Fill top row
        for (int i = left; i <= right; i++)
            matrix[top][i] = value++;
        top++;

        // Fill right column
        for (int i = top; i <= bottom; i++)
            matrix[i][right] = value++;
        right--;

        // Fill bottom row
        for (int i = right; i >= left; i--)
            matrix[bottom][i] = value++;
        bottom--;

        // Fill left column
        for (int i = bottom; i >= top; i--)
            matrix[i][left] = value++;
        left++;
    }

    // Print the matrix
    for (const auto& row : matrix) {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}