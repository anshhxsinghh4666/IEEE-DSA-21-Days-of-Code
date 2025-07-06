/*
Zigzag Character Matrix
Problem Statement:
Write a program that prints characters of a given string in a zigzag pattern in a matrix of size rows × columns.

Description:
You are given a string and the number of rows. Print the characters in a zigzag pattern across the matrix and fill empty cells with a space ' '. Then print the matrix row-wise.

Input Format:
1. A single string (non-empty, no whitespace)
2. An integer r representing the number of rows

Output Format:
Characters printed row-wise from the zigzag matrix with blank cells filled using a space ' '.

Sample Input:
PROGRAMMING
3

Sample Output:
P    R     I
 R G A M N
   O    M    G
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printZigzag(string text, int rows) {
    if (rows == 1 || rows >= text.length()) {
        cout << text << endl;
        return;
    }
    
    int len = text.length();
    vector<vector<char>> zigzag(rows, vector<char>(len, ' '));
    
    int row = 0, col = 0;
    bool down = true;
    
    for (int i = 0; i < len; i++) {
        zigzag[row][col++] = text[i];
        
        if (row == 0) {
            down = true;
        } else if (row == rows - 1) {
            down = false;
        }
        
        row += down ? 1 : -1;
    }
    
    // Print the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < len; j++) {
            cout << zigzag[i][j];
        }
        cout << endl;
    }
}

int main() {
    string input;
    int rows;
    cin >> input >> rows;
    printZigzag(input, rows);
    return 0;
}
