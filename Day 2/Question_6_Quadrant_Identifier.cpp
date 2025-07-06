/*
Quadrant Identifier (Sample Question)
Problem Statement:
Given coordinates (x, y), identify which quadrant they belong to or if they lie on an axis.

Description:
Use nested if-else conditions.

Input Format:
Two integers x and y.

Output Format:
Quadrant 1, 2, 3, 4 or Axis

Sample Input:
-4 5

Sample Output:
Quadrant 2
*/

#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if (x == 0 || y == 0) {
        cout << "Axis" << endl;
    }
    else if (x > 0 && y > 0) {
        cout << "Quadrant 1" << endl;
    }
    else if (x < 0 && y > 0) {
        cout << "Quadrant 2" << endl;
    }
    else if (x < 0 && y < 0) {
        cout << "Quadrant 3" << endl;
    }
    else {
        cout << "Quadrant 4" << endl;
    }

    return 0;
}
