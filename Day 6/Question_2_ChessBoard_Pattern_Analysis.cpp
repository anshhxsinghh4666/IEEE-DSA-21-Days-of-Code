/*
Problem Statement: Chessboard Pattern Analysis

You are given an n × n chessboard-like matrix where each cell contains either a 1 (indicating a white square) or a 0 (indicating a black square). The matrix follows the alternating pattern of a standard chessboard, but with some cells corrupted, breaking the pattern. Your task is to determine the minimum number of cells that need to be flipped (from 1 to 0 or from 0 to 1) to restore the matrix to a proper chessboard pattern.

Input Format:
The first line contains an integer n (where 2 ≤ n ≤ 500), representing the size of the matrix.
The next n lines each contain n integers (either 0 or 1), representing the matrix.

Output Format:
Output a single integer, the minimum number of cells that need to be flipped to restore the matrix to a proper chessboard pattern.

Constraints:
2 ≤ n ≤ 500

Each cell in the matrix is either 0 or 1.
The matrix may have at most 50% of its cells corrupted.

Example:
Input:
4
1 0 1 0
0 1 0 1
1 1 0 0
0 0 1 1

Output:
2

Explanation:
The provided 4 × 4 matrix should follow a chessboard pattern:

Pattern 1:
1 0 1 0
0 1 0 1
1 0 1 0
0 1 0 1

Pattern 2:
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0

We compare the given matrix with both Pattern 1 and Pattern 2. For Pattern 1, we need to flip the two bottom-right cells to make the matrix valid. For Pattern 2, we would need to flip more cells, so the optimal solution is to follow Pattern 1 with a total of 2 flips.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minFlips(int n, vector<vector<int>>& matrix) {
    int pattern1Flips = 0;
    int pattern2Flips = 0;
    
    // Calculate the flips for both patterns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Determine the expected value for both patterns
            int expectedPattern1 = (i + j) % 2;  // 0-1 alternating
            int expectedPattern2 = 1 - expectedPattern1;  // 1-0 alternating
            
            if (matrix[i][j] != expectedPattern1) {
                pattern1Flips++;
            }
            if (matrix[i][j] != expectedPattern2) {
                pattern2Flips++;
            }
        }
    }
    
    // Return the minimum number of flips required
    return min(pattern1Flips, pattern2Flips);
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n): ";
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    
    cout << "Enter the matrix values (each row on a new line):" << endl;
    // Input the matrix values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Calculate and print the result
    int result = minFlips(n, matrix);
    cout << "Minimum number of flips required: " << result << endl;
    
    return 0;
}

