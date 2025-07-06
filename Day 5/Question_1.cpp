/*
Problem Statement
You are tasked with creating a system to manage a series of mathematical calculations for a scientific research project. Specifically, you need to efficiently compute the area and perimeter of rectangles based on given dimensions. To optimize performance, you'll use inline functions.

You are required to:

Compute the area of a rectangle.
Compute the perimeter of a rectangle.
The computations must be handled using inline functions to ensure efficiency, especially when these functions are called frequently within your application.

Functions Required
inline float calculateArea(float width, float height): Calculates the area of a rectangle.
inline float calculatePerimeter(float width, float height): Calculates the perimeter of a rectangle.

Input
The first line will contain an integer named T which represents the number of test cases.
Each of the following T lines contains two floating-point numbers: the width and height of a rectangle.

Output
For each test case, output the area and perimeter of the rectangle, each rounded to two decimal places, on separate lines.

Constraints
1 ≤ T ≤ 100
0 < width, height ≤ 1000

Example
Input
3
5.0 10.0
7.5 8.5
3.0 4.0

Output
50.00
30.00
63.75
32.00
12.00
14.00

Explanation
For the first rectangle with width 5.0 and height 10.0:
Area = 5.0 * 10.0 = 50.00
Perimeter = 2 * (5.0 + 10.0) = 30.00
For the second rectangle with width 7.5 and height 8.5:
Area = 7.5 * 8.5 = 63.75
Perimeter = 2 * (7.5 + 8.5) = 32.00
For the third rectangle with width 3.0 and height 4.0:
Area = 3.0 * 4.0 = 12.00
Perimeter = 2 * (3.0 + 4.0) = 14.00
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Functions to calculate area and perimeter
float calculateArea(float width, float height) {
    return width * height;
}

float calculatePerimeter(float width, float height) {
    return 2 * (width + height);
}

int main() {
    int T;
    
    // Read the number of test cases
    cout << "Enter Number of Test Cases : ";
    cin >> T;
    
    while (T--) {
        float width, height;
        
        // Read width and height for each rectangle : 
        cout << " Enter Width : ";
        cin >> width;
        cout << "Enter Height : ";
        cin >> height;
        
        // Calculate and print the area
        float area = calculateArea(width, height);
        cout << fixed << setprecision(2) << "Area : " << area << endl;
        
        // Calculate and print the perimeter
        float perimeter = calculatePerimeter(width, height);
        cout << fixed << setprecision(2) << "Perimeter : " << perimeter << endl;
    }
    
    return 0;
}