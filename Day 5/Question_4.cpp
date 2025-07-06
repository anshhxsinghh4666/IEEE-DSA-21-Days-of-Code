/*
Problem Statement
You are developing a system for a logistics company that needs to track the shipments of packages. The system will categorize packages based on their weight and determine the cost of shipment based on distance and weight category. The company charges different rates for domestic and international shipments.

You need to implement different types of functions to calculate:

Weight Category: This function will bascially determine the weight category of the package.
Cost Calculation: This function calculates the shipment cost based on the weight category and distance.
Cost Display: This function displays the final cost along with the details of the shipment.
Weight Categories:
Lightweight: 0 < weight ≤ 5 kg
Standard: 5 < weight ≤ 20 kg
Heavy: 20 < weight ≤ 50 kg
Overweight: weight > 50 kg
Rate Table (per km):
Domestic:
Lightweight: $1.00
Standard: $1.50
Heavy: $2.00
Overweight: $3.00
International:
Lightweight: $2.00
Standard: $3.00
Heavy: $4.00
Overweight: $6.00

Input
The first line will contain an integer N which represents the number of packages.
The next N lines contain:
A float W representing the weight of the package.
An integer D will represent the distance in kilometers.
A string T will represent the type of shipment ("domestic" or "international").

Output
For each package, output the weight category, shipment type, and the calculated cost, each on a new line.

Constraints
1 ≤ N ≤ 50
0 < W ≤ 100
1 ≤ D ≤ 10000
T is either "domestic" or "international"

Example
Input
3
4.5 1000 domestic
15.0 2000 international
55.0 5000 domestic

Output
Lightweight
domestic
1000.00
Standard
international
6000.00
Overweight
domestic
15000.00

Explanation
The first package is categorized as Lightweight and is domestic, so the rate is $1.00 per km. The cost is 1000 * 1.00 = 1000.00.
The second package is categorized as Standard and is international, so the rate is $3.00 per km. The cost is 2000 * 3.00 = 6000.00.
The third package is categorized as Overweight and is domestic, so the rate is $3.00 per km. The cost is 5000 * 3.00 = 15000.00.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to determine weight category based on package weight
string determineWeightCategory(float weight) {
    if (weight > 0 && weight <= 5) {
        return "Lightweight";
    }
    else if (weight > 5 && weight <= 20) {
        return "Standard";
    }
    else if (weight > 20 && weight <= 50) {
        return "Heavy";
    }
    else if (weight > 50) {
        return "Overweight";
    }
    return "Unknown";  // Should not reach here with valid input
}

// Function to get rate per km based on weight category and shipment type
float getRate(string weightCategory, string shipmentType) {
    if (shipmentType == "domestic") {
        if (weightCategory == "Lightweight") return 1.00;
        else if (weightCategory == "Standard") return 1.50;
        else if (weightCategory == "Heavy") return 2.00;
        else if (weightCategory == "Overweight") return 3.00;
    }
    else if (shipmentType == "international") {
        if (weightCategory == "Lightweight") return 2.00;
        else if (weightCategory == "Standard") return 3.00;
        else if (weightCategory == "Heavy") return 4.00;
        else if (weightCategory == "Overweight") return 6.00;
    }
    return 0.0;  // Default case
}

// Function to calculate shipment cost based on weight category, distance, and type
float calculateShipmentCost(float weight, int distance, string shipmentType) {
    string weightCategory = determineWeightCategory(weight);
    float rate = getRate(weightCategory, shipmentType);
    return distance * rate;
}

// Function to display shipment details and cost
void displayShipmentDetails(float weight, int distance, string shipmentType) {
    string weightCategory = determineWeightCategory(weight);
    float cost = calculateShipmentCost(weight, distance, shipmentType);
    
    cout << weightCategory << endl;
    cout << shipmentType << endl;
    cout << fixed << setprecision(2) << cost << endl;
}

int main() {
    int N;
    cout << "Enter number of packages: ";
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        float weight;
        int distance;
        string shipmentType;
        
        // Read weight, distance, and shipment type
        cout << "Enter weight, distance, and shipment type (domestic/international): ";
        cin >> weight >> distance >> shipmentType;
        
        // Display shipment details and cost
        displayShipmentDetails(weight, distance, shipmentType);
    }
    
    return 0;
}