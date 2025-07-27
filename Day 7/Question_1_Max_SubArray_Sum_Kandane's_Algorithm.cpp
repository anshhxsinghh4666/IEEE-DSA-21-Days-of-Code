/*
"Maximum Subarray Sum (Kadane’s Algorithm with Indices)
Problem Statement:
Write a program to find the contiguous subarray with the maximum sum in a given array and print both the sum and indices of the subarray.

Description:
Implement Kadane’s Algorithm to track the start and end indices of the maximum sum subarray.

Input Format:
An integer n
n space-separated integers

Output Format:
Maximum subarray sum
Start and end indices (0-based)

Sample Input:
9
-2 -3 4 -1 -2 1 5 -3 2

Sample Output:
7
2 6


"
*/


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int max_sum = a[0];
    int curr_sum = a[0];
    int start = 0, end = 0, temp_start = 0;
    
    for(int i = 1; i < n; i++) {
        if(a[i] > curr_sum + a[i]) {
            curr_sum = a[i];
            temp_start = i;
        } else {
            curr_sum += a[i];
        }
        
        if(curr_sum > max_sum) {
            max_sum = curr_sum;
            start = temp_start;
            end = i;
        }
    }
    
    cout << max_sum << endl;
    cout << start << " " << end << endl;
    
    return 0;
}