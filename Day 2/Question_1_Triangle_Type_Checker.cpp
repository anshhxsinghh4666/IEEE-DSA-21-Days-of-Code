/*
Triangle Type Checker
Problem Statement:
Write a program that determines if a triangle is Equilateral, Isosceles, or Scalene.

Description:
Read three integers and use conditional statements to classify the triangle.

Input Format:
Three integers representing sides of a triangle.

Output Format:
"Equilateral", "Isosceles", or "Scalene"

Sample Input:
3 3 3

Sample Output:
Equilateral
*/


#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout<<"Enter A : ";
    cin >> a;
    cout<<"Enter B : ";
    cin>>b;
    cout<<"Enter C : ";
    cin>>c;
    
    if (a == b && b == c) {
        cout << "Equilateral";
    } else if (a == b || b == c || a == c) {
        cout << "Isosceles";
    } else {
        cout << "Scalene";
    }
    
    return 0;
}