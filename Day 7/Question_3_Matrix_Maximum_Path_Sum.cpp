/*
"Matrix Maximum Path Sum with Constraints
Problem Statement:
Write a program to find the maximum sum path from top-left to bottom-right of an n x n matrix, moving only right, down, or diagonally (i+1, j+1). You cannot revisit any cell.

Description:
Use recursion and memoization (DP) to find the path with the maximum sum considering the allowed directions.

Input Format:
An integer n
n lines of n space-separated integers

Output Format:
An integer representing the maximum path sum

Sample Input:
3
1 2 3
4 5 6
7 8 9

Sample Output:
29


"
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> mat;
vector<vector<int>> dp;

int maxPath(int i, int j) {
    if (i >= n || j >= n) {
        return 0;
    }
    
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int right = maxPath(i, j + 1);
    int down = maxPath(i + 1, j);
    int diag = maxPath(i + 1, j + 1);
    
    dp[i][j] = mat[i][j] + max({right, down, diag});
    return dp[i][j];
}

int main() {
    cin >> n;
    
    mat.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(n, -1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    
    cout << maxPath(0, 0) << endl;
    
    return 0;
}