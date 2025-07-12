/*
Problem Statement: Warehouse Inventory Optimization
You are the manager of a large warehouse that stores different types of products. The warehouse is organized in a 3D grid (length, width, height), where each position in the grid represents a storage bin. Each bin will contain a specific number of the products. Your goal is to find the maximum number of products stored within a rectangular block of bins in the grid, defined by any two opposite corners.

Given a 3D grid of integers representing the number of products in each bin, write a C program to calculate the maximum number of products stored within any rectangular sub-block of bins.

Input:
The first line will contain three integers named L, W, and H which are representing the length, width, and height of the warehouse grid.
The next L * W * H lines contain integers representing the number of products stored in each bin.

Output:
A single integer representing the maximum number of products stored within any sub-block of bins.

Constraints:
2 <= L, W, H <= 50 (Warehouse dimensions are between 2x2x2 and 50x50x50).
0 <= products[i][j][k] <= 1000 (Number of products in each bin is between 0 and 1000).

Explanation:
To solve the problem, we need to efficiently compute the sum of products within any sub-block of bins. This can be done by utilizing a 3D prefix sum array to quickly compute the sum of any sub-block using inclusion-exclusion principles.

The 3D prefix sum array prefix[i][j][k] stores the sum of all products in the sub-block from the origin (0,0,0) to the current position (i,j,k). Once the prefix sums are calculated, finding the sum of products for any arbitrary sub-block defined by two opposite corners is fast.

Example:
Input:
3 3 3
1 2 3
4 5 6
7 8 9
10 11 12
13 14 15
16 17 18
19 20 21
22 23 24
25 26 27

Output:
351

Explanation: The largest sub-block (the entire grid) has a sum of 351, which is the sum of all bins in the grid.
*/


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<vector<int>>> calculatePrefixSum(int L, int W, int H, const vector<vector<vector<int>>>& grid) {
    vector<vector<vector<int>>> prefix(L, vector<vector<int>>(W, vector<int>(H, 0)));
    
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < H; k++) {
                prefix[i][j][k] = grid[i][j][k];
                
                if (i > 0) {
                    prefix[i][j][k] += prefix[i-1][j][k];
                }
                if (j > 0) {
                    prefix[i][j][k] += prefix[i][j-1][k];
                }
                if (k > 0) {
                    prefix[i][j][k] += prefix[i][j][k-1];
                }
                
                if (i > 0 && j > 0) {
                    prefix[i][j][k] -= prefix[i-1][j-1][k];
                }
                if (i > 0 && k > 0) {
                    prefix[i][j][k] -= prefix[i-1][j][k-1];
                }
                if (j > 0 && k > 0) {
                    prefix[i][j][k] -= prefix[i][j-1][k-1];
                }
                
                if (i > 0 && j > 0 && k > 0) {
                    prefix[i][j][k] += prefix[i-1][j-1][k-1];
                }
            }
        }
    }
    
    return prefix;
}

int sumOfSubblock(const vector<vector<vector<int>>>& prefix, int x1, int y1, int z1, int x2, int y2, int z2) {
    int sumVal = prefix[x2][y2][z2];
    
    if (x1 > 0) {
        sumVal -= prefix[x1-1][y2][z2];
    }
    if (y1 > 0) {
        sumVal -= prefix[x2][y1-1][z2];
    }
    if (z1 > 0) {
        sumVal -= prefix[x2][y2][z1-1];
    }
    
    if (x1 > 0 && y1 > 0) {
        sumVal += prefix[x1-1][y1-1][z2];
    }
    if (x1 > 0 && z1 > 0) {
        sumVal += prefix[x1-1][y2][z1-1];
    }
    if (y1 > 0 && z1 > 0) {
        sumVal += prefix[x2][y1-1][z1-1];
    }
    
    if (x1 > 0 && y1 > 0 && z1 > 0) {
        sumVal -= prefix[x1-1][y1-1][z1-1];
    }
    
    return sumVal;
}

int main() {
    int L, W, H;
    cout << "Enter length, width, and height of the warehouse: ";
    cin >> L >> W >> H;
    
    // Reading the grid
    vector<vector<vector<int>>> grid(L, vector<vector<int>>(W, vector<int>(H)));
    cout << "Enter the number of products in each bin (L*W*H values):" << endl;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < H; k++) {
                cin >> grid[i][j][k];
            }
        }
    }
    
    // Calculate the 3D prefix sum
    cout << "Calculating 3D prefix sum..." << endl;
    auto prefix = calculatePrefixSum(L, W, H, grid);
    cout << "Prefix sum calculation complete." << endl;
    
    // Find the maximum sum in any sub-block
    int maxSum = INT_MIN;
    cout << "Searching for maximum sum sub-block..." << endl;
    for (int x1 = 0; x1 < L; x1++) {
        for (int y1 = 0; y1 < W; y1++) {
            for (int z1 = 0; z1 < H; z1++) {
                for (int x2 = x1; x2 < L; x2++) {
                    for (int y2 = y1; y2 < W; y2++) {
                        for (int z2 = z1; z2 < H; z2++) {
                            int currentSum = sumOfSubblock(prefix, x1, y1, z1, x2, y2, z2);
                            // Uncomment below to see every sub-block sum:
                            // cout << "Sub-block [(" << x1 << "," << y1 << "," << z1 << ") to (" << x2 << "," << y2 << "," << z2 << ")] sum: " << currentSum << endl;
                            if (currentSum > maxSum) {
                                cout << "New max found: " << currentSum << " for sub-block [(" << x1 << "," << y1 << "," << z1 << ") to (" << x2 << "," << y2 << "," << z2 << ")]" << endl;
                                maxSum = currentSum;
                            }
                        }
                    }
                }
            }
        }
    }
    
    // Output the result
    cout << "Maximum number of products in any sub-block: " << maxSum << endl;
    
    return 0;
}