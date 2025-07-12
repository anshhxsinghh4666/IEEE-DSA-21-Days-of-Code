/*
Problem Statement: Survivor Grid
You are given a grid representing a battle zone, where each cell has a certain number of soldiers. Some of the cells are designated as "safe zones" (represented by 0 soldiers), which are protected and cannot be attacked. Your task is to simulate a strategic attack where you can choose to attack a group of connected cells in the grid.

Cells are considered connected if they share a side (left, right, up, or down) with another cell containing soldiers. When you attack a connected group of cells, all the soldiers in that group are eliminated, and the total number of soldiers eliminated is counted.

Your goal is to find the maximum number of soldiers you can eliminate in a single attack on a connected group of cells.

Input Format:
The first line contains two integers n and m (where 2 ≤ n, m ≤ 500), representing the number of rows and columns in the grid.
The next n lines each contain m integers, representing the number of soldiers in each cell of the grid. A value of 0 in the grid represents a "safe zone" that cannot be attacked or crossed.

Output Format:
Output a single integer, the maximum number of soldiers you can eliminate in a single attack.

Constraints:
2 ≤ n, m ≤ 500
The number of soldiers in any cell will be between 1 and 1000, except for safe zones which have 0 soldiers.
The grid contains at least one cell with soldiers (≥ 1).

Example:

Input:
5 5
10 0 0 10 0
10 10 0 10 0
0 0 0 10 10
10 10 0 0 0
10 0 10 10 10

Output:
50
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Directions for moving up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] > 0 && !visited[x][y]);
}

int dfs(int x, int y, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    visited[x][y] = true;
    int soldiers = grid[x][y];
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, n, m, grid, visited)) {
            soldiers += dfs(nx, ny, n, m, grid, visited);
        }
    }
    
    return soldiers;
}

int findMaxSoldiers(int n, int m, vector<vector<int>>& grid) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int maxSoldiers = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] > 0 && !visited[i][j]) {
                cout << "Starting DFS at cell (" << i << ", " << j << ") with " << grid[i][j] << " soldiers." << endl;
                int currentSoldiers = dfs(i, j, n, m, grid, visited);
                cout << "Connected group at (" << i << ", " << j << ") has " << currentSoldiers << " soldiers." << endl;
                if (currentSoldiers > maxSoldiers) {
                    cout << "New maximum found: " << currentSoldiers << " soldiers." << endl;
                    maxSoldiers = currentSoldiers;
                }
            }
        }
    }
    
    return maxSoldiers;
}

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    
    // Input grid data
    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the grid values (each row on a new line):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Find and print the maximum number of soldiers that can be eliminated in a single attack
    int result = findMaxSoldiers(n, m, grid);
    cout << "Maximum number of soldiers that can be eliminated in a single attack: " << result << endl;
    
    return 0;
}