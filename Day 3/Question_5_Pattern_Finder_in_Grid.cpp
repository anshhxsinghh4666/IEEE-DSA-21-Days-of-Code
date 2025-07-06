/*
Pattern Finder in Grid
Problem Statement:
Given a character grid, find how many times a given word appears in all 8 directions.

Description:
Use loops to check horizontally, vertically, and diagonally.

Input Format:
First line: m and n
Next m lines: n characters each
Last line: word to search

Output Format:
Number of times the word appears

Sample Input:
3 3
A B C
D E F
G H I
ABC

Sample Output:
1
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool isValid(const vector<vector<char>>& grid, int x, int y, const string& word) {
    int m = grid.size(), n = grid[0].size(), len = word.length();
    for (int dir = 0; dir < 8; dir++) {
        int k, nx = x, ny = y;
        for (k = 0; k < len; k++) {
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != word[k])
                break;
            nx += dx[dir];
            ny += dy[dir];
        }
        if (k == len) return true;
    }
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;
    cin.ignore(); // Skip newline after reading dimensions

    vector<vector<char>> grid(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        string line;
        getline(cin, line);
        line.erase(remove(line.begin(), line.end(), ' '), line.end()); // Remove spaces
        if (line.length() != n) {
            cout << "Invalid row input. Each row must have exactly " << n << " characters." << endl;
            return 1;
        }
        for (int j = 0; j < n; j++)
            grid[i][j] = line[j];
    }

    string word;
    if (!getline(cin, word)) {
        cout << "Missing word input." << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (isValid(grid, i, j, word))
                count++;

    cout << count << endl;
    return 0;
}