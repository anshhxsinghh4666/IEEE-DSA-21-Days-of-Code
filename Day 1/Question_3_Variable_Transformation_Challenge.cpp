/*
Variable Transformation Challenge
Problem Statement:
In a parallel universe, the concept of variable transformation is quite different. You need to write a Java program that performs a series of operations on variables based on specific conditions. Given three integers 
a, b, and c, your task is to transform these variables according to the following rules and output the final values.

Description:
If 
a is even, add b toa.
If 
b is odd, multiply c by 2.
If c is a multiple of 3, add a to c.
If the sum of a, b, and c is greater than 100, subtract 100 from each of a, b, and c.
Your program should then print the transformed values of 
a, b, and c in the format "a: [value], b: [value], c: [value]".

Input Format:
Three integers 
a, b, and c are given as input from the user, each on a new line.
Output Format:
Print the transformed values of 
a, b, and c in the specified format.

Sample input:
10
15
9
Sample output:
a: 25, b: 15, c: 43
*/


#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    
    // Input
    cout<<"Enter a : ";
    cin >> a;
    cout<<"Enter b : ";
    cin >> b;
    cout<<"Enter c : ";
    cin >> c;
    

    // Transformations
    if (a % 2 == 0) {
        a += b;
    }
    if (b % 2 != 0) {
        c *= 2;
    }
    if (c % 3 == 0) {
        c += a;
    }
    if (a + b + c > 100) {
        a -= 100;
        b -= 100;
        c -= 100;
    }

    // Output (corrected string quotes)
    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;

    return 0;
}