/*
Boolean Operators
Problem Statement:
Write a program that uses boolean operators to evaluate complex conditions. The program should determine if a person qualifies for a special discount based on multiple criteria.

Description:
The program should take three boolean inputs representing whether a person is a senior citizen, a student, and if they have a membership card. The program should output true if the person qualifies for the discount and false otherwise. A person qualifies if they meet at least two out of the three criteria.

Input Format:

Three boolean values separated by spaces.
Output Format:
A single boolean value (TRUE or FALSE).
Sample Input:
true false true
Sample Output:
TRUE
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    bool senior, student, member;
    string input;

    // Read inputs (0 or 1)
    cout << "Enter senior status (0/1): ";
    cin >> input;
    senior = stoi(input);

    cout << "Enter student status (0/1): ";
    cin >> input;
    student = stoi(input);

    cout << "Enter member status (0/1): ";
    cin >> input;
    member = stoi(input);

    // Check qualification
    bool qualifies = (senior && student) || (senior && member) || (student && member);

    // Output TRUE or FALSE (uppercase)
    cout << (qualifies ? "TRUE" : "FALSE") << endl;

    return 0;
}