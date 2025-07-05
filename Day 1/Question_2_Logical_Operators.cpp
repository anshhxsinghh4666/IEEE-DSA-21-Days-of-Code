/*
Logical Operators
Problem Statement:
Create a program that uses logical operators to check the validity of a password based on multiple conditions.

Description:
The program should check if the password contains at least one uppercase letter, one lowercase letter, one digit, and is at least 8 characters long. It should output true if all conditions are met and false otherwise.

Input Format:

A single string representing the password.
Output Format:

A single boolean value (TRUE or FALSE).

Sample Input:
password
Sample Output:
FALSE
*/

#include <iostream>
#include <string>
#include <cctype> // for isupper(), islower(), isdigit()

int main() {
    std::string password;
    std::cout<<"Enter Password : ";
    std::getline(std::cin, password); // Read entire line (including spaces)

    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;
    const bool isLongEnough = password.length() >= 8;

    // Check each character
    for (char c : password) {
        if (isupper(c)) hasUppercase = true;
        if (islower(c)) hasLowercase = true;
        if (isdigit(c)) hasDigit = true;

        // Early exit if all conditions are met
        if (hasUppercase && hasLowercase && hasDigit) break;
    }

    const bool isValid = hasUppercase && hasLowercase && hasDigit && isLongEnough;
    std::cout << std::boolalpha << isValid << std::endl;

    return 0;
}