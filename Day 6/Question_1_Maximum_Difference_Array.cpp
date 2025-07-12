/*
Title: Maximum Difference in Array

Problem Statement:
You are given an array of integers, and you need to find the maximum difference between any two elements in the array. The difference is defined as the absolute difference between the two elements. The array may contain both positive and negative numbers, and your task is to ensure the difference calculation considers all possible pairs within the array.

Input:

The first line contains an integer N (1 ≤ N ≤ 1000) representing the number of elements in the array.
The second line contains N space-separated integers representing the elements of the array A[i] (-10^5 ≤ A[i] ≤ 10^5).

Output:

A single integer, the maximum difference between any two elements in the array.

Constraints:

1 ≤ N ≤ 1000
-10^5 ≤ A[i] ≤ 10^5

Example:

Example 1:
Input:
5
1 -3 2 10 6

Output:
13

Explanation:
The maximum difference is between -3 and 10, which is |10 - (-3)| = 13.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    
    cout << "Minimum value in array: " << minVal << endl;
    cout << "Maximum value in array: " << maxVal << endl;
    
    int maxDifference = abs(maxVal - minVal);
    
    cout << "Maximum difference: " << maxDifference << endl;
    
    return 0;
}