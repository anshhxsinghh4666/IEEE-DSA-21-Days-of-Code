/*
Binary Operators
Problem Statement:
Create a program that calculates the bitwise AND, OR, XOR, and NOT operations on two integers provided by the user.

Description:
The program should read two integers and then compute and display the results of the bitwise AND, OR, XOR, and NOT operations.

Input Format:

Two integers separated by a space.
Output Format:

Four lines, each representing the result of bitwise AND, OR, XOR, and NOT operations respectively.

Sample Input:
10 4
Sample Output:

Bitwise AND: 0
Bitwise OR: 14
Bitwise XOR: 14
Bitwise NOT (first number): -11
*/

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout<<"Enter A : ";
    cin >> a;
    cout<<"Enter B : ";
    cin >> b; 

    cout << "Bitwise AND: " << (a & b) << endl;
    cout << "Bitwise OR: " << (a | b) << endl;
    cout << "Bitwise XOR: " << (a ^ b) << endl;
    cout << "Bitwise NOT (first number): " << (~a) << endl;

    return 0;
}