/*
Inverted Hourglass Pattern
Problem Statement:
Construct an inverted hourglass using digits with increasing symmetry.

Description:
Print an hourglass of digits that inverts from a wide top to a narrow center and expands again at the bottom.

Input Format:
Integer n

Output Format:
Inverted hourglass using digits

Sample Input:
4

Sample Output:
4 4 4 4 4 4 4
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4
*/

#include <iostream>
#include <algorithm>
using namespace std;

void printHourglass(int n) {
    int size = 2 * n - 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int val = n - min({i, j, size - 1 - i, size - 1 - j});
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter N : ";
    cin >> n;
    printHourglass(n);
    return 0;
}