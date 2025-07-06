/*
Problem Statement
You are developing a system for a food delivery service that needs to handle multiple customer orders. Each order includes a list of items, each with a specific quantity and price. You need to implement functions to:

Calculate the total cost of each order.
Apply a discount based on the total cost of the order.
Determine the final price after applying the discount.
The system should handle multiple orders and output the final price for each order.

Functions Required
calculateTotalCost(float prices[], int quantities[], int n): This function calculates the total cost of an order based on the prices and quantities of the items.
applyDiscount(float totalCost): This function applies a discount to the total cost. The discount is as follows:
If the total cost is less than $50, then there will be no discount.
If the total cost is between $50 and $100, a 10% discount.
If the total cost is more than $100, a 20% discount.
finalPriceAfterDiscount(float totalCost): This function calculates the final price after applying the discount.

Input
The first line contains an integer N representing the number of orders.
The next N lines each contain:
An integer M representing the number of items in the order.
M pairs of floating-point numbers where each pair represents the price and quantity of an item.

Output
For each order, output the final price after applying the discount, rounded to two decimal places.

Constraints
1 ≤ N ≤ 100
1 ≤ M ≤ 50
0 < prices[i] ≤ 500
0 < quantities[i] ≤ 100

Example
Input
2
3 10.0 2 20.0 1 5.0 3
4 15.0 1 25.0 2 10.0 2

Output
28.00
67.50

Explanation
For the first order:

Total cost = (10.0 * 2) + (20.0 * 1) + (5.0 * 3) = 20.0 + 20.0 + 15.0 = 55.0
Discount = 10% of 55.0 = 5.50
Final price = 55.0 - 5.50 = 49.50
For the second order:

Total cost = (15.0 * 1) + (25.0 * 1) + (10.0 * 2) = 15.0 + 25.0 + 20.0 = 60.0
Discount = 10% of 60.0 = 6.00
Final price = 60.0 - 6.00 = 54.00
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

float calculateTotalCost(const vector<float>& prices, const vector<int>& quantities, int n) {
    float total = 0.0f;
    for (int i = 0; i < n; ++i) {
        total += prices[i] * quantities[i];
    }
    return total;
}

float applyDiscount(float totalCost) {
    if (totalCost < 50.0f) {
        return 0.0f;
    } else if (totalCost <= 100.0f) {
        return totalCost * 0.10f;
    } else {
        return totalCost * 0.20f;
    }
}

float finalPriceAfterDiscount(float totalCost) {
    float discount = applyDiscount(totalCost);
    return totalCost - discount;
}

int main() {
    int N;
    cout << "Enter number of orders: ";
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        int M;
        cout << "Enter number of items in order " << (i + 1) << ": ";
        cin >> M;
        
        vector<float> prices;
        vector<int> quantities;
        
        for (int j = 0; j < M; ++j) {
            float price;
            int quantity;
            cout << "Enter price and quantity for item " << (j + 1) << ": ";
            cin >> price >> quantity;
            prices.push_back(price);
            quantities.push_back(quantity);
        }
        
        float totalCost = calculateTotalCost(prices, quantities, M);
        float finalPrice = finalPriceAfterDiscount(totalCost);
        
        cout << "Total cost before discount: " << fixed << setprecision(2) << totalCost << endl;
        cout << "Final price after discount: " << fixed << setprecision(2) << finalPrice << endl;
    }
    
    return 0;
}