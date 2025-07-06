/*
Chessboard Move Validator
Problem Statement:
Write a program to validate if a chess piece (Queen, Rook, Bishop, or Knight) can legally move from position A to position B based on chess rules.

Description:
You must implement move logic for each piece using if-else and validate legality of movement.

Input Format:
Three strings — piece (Queen/Rook/Bishop/Knight), positionA (e.g., A2), positionB (e.g., D5)

Output Format:
Valid / Invalid

Sample Input:
Queen A1 D4

Sample Output:
Valid
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype> // for toupper
#include <cmath>  // for abs
#include <sstream> // for stringstream

using namespace std;

int to_num(char c) {
    c = toupper(c);
    if (c < 'A' || c > 'H') {
        return -1; // Invalid column
    }
    return c - 'A' + 1;
}

bool is_valid(const string& piece, int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return false; // Same position
    }

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    if (piece == "Rook") {
        return x1 == x2 || y1 == y2;
    }
    else if (piece == "Bishop") {
        return dx == dy;
    }
    else if (piece == "Queen") {
        return x1 == x2 || y1 == y2 || dx == dy;
    }
    else if (piece == "Knight") {
        return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    }
    else {
        return false; // Invalid piece name
    }
}

int main() {
    string input_line;
    getline(cin, input_line);
    stringstream ss(input_line);
    
    string piece, from_pos, to_pos;
    ss >> piece >> from_pos >> to_pos;

    // Validate we got exactly 3 inputs
    if (ss.fail() || !ss.eof()) {
        cout << "Invalid" << endl;
        return 0;
    }

    // Convert to uppercase
    for (char &c : from_pos) c = toupper(c);
    for (char &c : to_pos) c = toupper(c);

    // Validate piece name
    vector<string> valid_pieces = {"Rook", "Bishop", "Queen", "Knight"};
    bool valid_piece = false;
    for (const auto& p : valid_pieces) {
        if (piece == p) {
            valid_piece = true;
            break;
        }
    }

    if (!valid_piece || from_pos.length() != 2 || to_pos.length() != 2) {
        cout << "Invalid" << endl;
        return 0;
    }

    // Convert and validate coordinates
    int x1 = to_num(from_pos[0]);
    int y1 = from_pos[1] - '0';
    int x2 = to_num(to_pos[0]);
    int y2 = to_pos[1] - '0';

    if (x1 == -1 || x2 == -1 || y1 < 1 || y1 > 8 || y2 < 1 || y2 > 8) {
        cout << "Invalid" << endl;
    }
    else {
        cout << (is_valid(piece, x1, y1, x2, y2) ? "Valid" : "Invalid") << endl;
    }

    return 0;
}