/*
"Find K-th Unique Element
Problem Statement:
Given an array, find the K-th unique element (not repeating) using linear search logic. If fewer than K unique elements exist, return -1.

Description:
This program scans the array for elements that appear only once and returns the K-th such unique value.

Input Format:
Line 1: Two integers n (size of array) and k (required unique index)
Line 2: n space-separated integers

Output Format:
K-th unique number or −1 if not found

Sample Input:
8 2
4 5 1 2 1 4 3 6

Sample Output:
2


"
*/


#include <iostream>
#include <vector>

using namespace std;

int firstOccurrence(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Continue searching left half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int lastOccurrence(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1; // Continue searching right half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int n, target;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cin >> target;
    
    int first = firstOccurrence(arr, target);
    int last = lastOccurrence(arr, target);
    
    if (first == -1) {
        cout << 0 << endl;
    } else {
        cout << (last - first + 1) << endl;
    }
    
    return 0;
}