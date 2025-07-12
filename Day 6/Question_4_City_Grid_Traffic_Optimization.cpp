/*
Problem Statement: City Grid Traffic Optimization
You are given a city represented as a 2D grid of intersections, where each element in the grid represents the time (in minutes) it takes for traffic to pass through that intersection. The city mayor wants to optimize traffic flow by finding the fastest route from the top-left corner of the city to the bottom-right corner. You are allowed to move only right or down at any intersection.

Given a matrix M x N representing the city grid, where each value at grid[i][j] represents the time required at the (i, j) intersection, write a C program that finds the minimum total time required to move from the top-left corner (0,0) to the bottom-right corner (M-1, N-1).

Input:
The first line contains two integers M and N — the number of rows and columns of the grid.
The next M lines each contain N integers representing the city grid, where each integer is the time in minutes for that particular intersection.

Output:
A single integer, the minimum time required to travel from the top-left to the bottom-right corner.

Constraints:
2 <= M, N <= 100 (grid size between 2x2 and 100x100)
1 <= grid[i][j] <= 100 (time taken at each intersection is between 1 and 100 minutes)

Explanation:
The idea is to use a dynamic programming approach to compute the minimum time at each intersection. From the top-left corner (0, 0), for any intersection (i, j), you can only arrive from either the intersection directly above (i-1, j) or the one directly to the left (i, j-1).

We need to compute the minimum time required to reach each intersection (i, j) using the relation:
min_time[i][j] = grid[i][j] + min(min_time[i-1][j], min_time[i][j-1])
The value at min_time[M-1][N-1] will give the answer.

Example:
Input:
3 3
4 7 8
6 5 9
3 2 1

Output:
18

Explanation: The best route is to move like this:
(0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2)
The total time will be 4 + 7 + 8 + 9 + 1 = 18.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    
    // Reading the grid
    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Initialize min_time array
    vector<vector<int>> minTime(M, vector<int>(N));
    
    // Initialize the first cell
    minTime[0][0] = grid[0][0];
    
    // Fill the first row (only right moves)
    for (int j = 1; j < N; j++) {
        minTime[0][j] = minTime[0][j-1] + grid[0][j];
    }
    
    // Fill the first column (only down moves)
    for (int i = 1; i < M; i++) {
        minTime[i][0] = minTime[i-1][0] + grid[i][0];
    }
    
    // Fill the rest of the grid
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            minTime[i][j] = grid[i][j] + min(minTime[i-1][j], minTime[i][j-1]);
        }
    }
    
    // Output the result (bottom-right corner)
    cout << minTime[M-1][N-1] << endl;
    
    return 0;
}