/*
Problem Statement
You have been tasked with developing a software system for an online bookstore. The system needs to process orders based on a variety of book categories and compute discounts based on membership status. The bookstore offers three main categories of books: Fiction, Non-Fiction, and Educational.

You need to create a program that defines and declares functions to calculate the total cost of an order after applying any relevant discounts.

Here’s how the discount system works:

Fiction: No discount.
Non-Fiction: A 10% discount for members and 5% for non-members.
Educational: A 20% discount for members and 10% for non-members.
The system should handle multiple orders, each specifying the category of books, the total price of the books before the discount, and whether the customer is a member.

Input
The first line contains an integer named N, which implies to the number of orders.
The next N lines each contain a string C (the category of the books), a floating-point number P (the total price before discount), and a string M (indicating membership status: "member" or "non-member").

Output
For each order, output the final price after applying the discount, rounded to two decimal places.

Constraints
1 ≤ N ≤ 100
0 < P ≤ 10000
C is one of "Fiction", "Non-Fiction", "Educational"
M is either "member" or "non-member"

Example
Input
3
Fiction 150.00 member
Non-Fiction 200.00 non-member
Educational 500.00 member

Output
150.00
190.00
400.00

Explanation
For the first order, there is no discount on Fiction, so the price remains 150.00.
For the second order, a 5% discount is applied to Non-Fiction because the customer is a non-member, reducing the price to 190.00.
For the third order, a 20% discount is applied to Educational books for a member, reducing the price to 400.00.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to calculate discount percentage based on category and membership
float getDiscountPercentage(string category, string membership) {
    if (category == "Fiction") {
        return 0.0;  // No discount for Fiction
    }
    else if (category == "Non-Fiction") {
        if (membership == "member") {
            return 0.10;  // 10% discount for members
        } else {
            return 0.05;  // 5% discount for non-members
        }
    }
    else if (category == "Educational") {
        if (membership == "member") {
            return 0.20;  // 20% discount for members
        } else {
            return 0.10;  // 10% discount for non-members
        }
    }
    return 0.0;  // Default no discount
}

// Function to calculate final price after discount
float calculateFinalPrice(float originalPrice, string category, string membership) {
    float discountPercentage = getDiscountPercentage(category, membership);
    float discountAmount = originalPrice * discountPercentage;
    return originalPrice - discountAmount;
}

// Function to apply discount and return final price
float applyDiscount(float price, string category, string membership) {
    return calculateFinalPrice(price, category, membership);
}

int main() {
    int N;
    cout << "Enter number of orders: ";
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string category, membership;
        float price;
        
        // Read category, price, and membership status
        cout << "Enter category, price, and membership (e.g. Fiction 150.00 member): ";
        cin >> category >> price >> membership;
        
        // Calculate final price after applying discount
        float finalPrice = applyDiscount(price, category, membership);
        
        // Output the final price rounded to 2 decimal places
        cout << fixed << setprecision(2) << finalPrice << endl;
    }
    
    return 0;
}