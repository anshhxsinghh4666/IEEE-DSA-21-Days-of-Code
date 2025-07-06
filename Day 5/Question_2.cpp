/*
Problem Statement
You are developing a system to manage employee bonuses based on their performance scores and work hours. The system needs to handle various types of functions to calculate bonuses using different strategies. You will need to implement the functions that:

Calculate the base bonus based on performance scores.
Calculate additional bonuses based on work hours.
Apply a special adjustment based on employee type (full-time or part-time).
Functions Required
float calculateBaseBonus(float performanceScore): Calculates the base bonus based on performance score.
float calculateAdditionalBonus(float workHours): Calculates the additional bonus based on work hours.
float applyAdjustment(float bonus, char employeeType): Applies a special adjustment based on whether the employee is full-time or part-time.
Note: The special adjustment is:

Full-time: No adjustment.
Part-time: 5% reduction in the total bonus.

Input
The first line contains an integer N representing the number of employees.
The next N lines each contain:
A floating-point number representing the performance score.
A floating-point number representing the total work hours.
A character representing the employee type ('F' for full-time, 'P' for part-time).

Output
For each employee, output the final bonus amount after applying the adjustment, rounded to two decimal places.

Constraints
1 ≤ N ≤ 100
0 ≤ performanceScore ≤ 100
0 ≤ workHours ≤ 200
employeeType ∈ {'F', 'P'}

Example
Input
5500.00
1330.00
7000.00

Output
5500.00
1330.00
7000.00

Explanation
For the first employee:

Base bonus = 85.0 * 50 = 4250.00
Additional bonus = 40.0 * 10 = 400.00
Total bonus before adjustment = 4250.00 + 400.00 = 4650.00
Adjustment (full-time) = 0%
Final bonus = 4650.00
For the second employee:

Base bonus = 75.0 * 50 = 3750.00
Additional bonus = 35.0 * 10 = 350.00
Total bonus before adjustment = 3750.00 + 350.00 = 4100.00
Adjustment (part-time) = 5%
Final bonus = 4100.00 * 0.95 = 3895.00
For the third employee:

Base bonus = 90.0 * 50 = 4500.00
Additional bonus = 50.0 * 10 = 500.00
Total bonus before adjustment = 4500.00 + 500.00 = 5000.00
Adjustment (full-time) = 0%
Final bonus = 5000.00
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Calculate the base bonus based on performance score
float calculateBaseBonus(float performanceScore) {
    return performanceScore * 50;
}

// Calculate additional bonus based on work hours
float calculateAdditionalBonus(float workHours) {
    return workHours * 10;
}

// Apply special adjustment based on employee type
float applyAdjustment(float bonus, char employeeType) {
    if (employeeType == 'P') {
        return bonus * 0.95;  // 5% reduction for part-time
    }
    return bonus;  // No adjustment for full-time
}

int main() {
    int N;
    cin >> N;
    
    while (N--) {
        float performanceScore, workHours;
        char employeeType;
        
        cin >> performanceScore >> workHours >> employeeType;
        
        // Calculate base and additional bonuses
        float baseBonus = calculateBaseBonus(performanceScore);
        float additionalBonus = calculateAdditionalBonus(workHours);
        
        // Calculate total bonus before adjustment
        float totalBonus = baseBonus + additionalBonus;
        
        // Apply adjustment based on employee type
        float finalBonus = applyAdjustment(totalBonus, employeeType);
        
        // Output the final bonus rounded to 2 decimal places
        cout << fixed << setprecision(2) << finalBonus << endl;
    }
    
    return 0;
}