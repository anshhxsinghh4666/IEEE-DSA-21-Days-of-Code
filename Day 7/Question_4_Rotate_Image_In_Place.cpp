/*
"Rotate Image In-place (90 Degrees Clockwise)
Problem Statement:
Write a program to rotate an n×n 2D matrix 90 degrees clockwise in-place.

Description:
First transpose the matrix, then reverse each row.

Input Format:

An integer n (size of matrix)

n lines, each with n space-separated integers

Output Format:

The rotated matrix

Sample Input:
4
1  2  3  4
5  6  7  8
9 10 11 12
13 14 15 16

Sample Output:
13  9  5 1
14 10  6 2
15 11  7 3
16 12  8 4


"
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Reverse each row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> mat(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    
    rotate(mat);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j];
            if (j < n - 1) cout << "" "";
        }
        cout << endl;
    }
    
    return 0;
}
