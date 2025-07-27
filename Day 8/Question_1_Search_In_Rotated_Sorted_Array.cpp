/*
"Search in Rotated Sorted Array
Problem Statement:
Write a program to search for an element in a rotated sorted array using binary search.

Description:
A rotated sorted array is an array that was originally sorted but then rotated. Use modified binary search to find the element.

Input Format:
Line 1: n (size of array)
Line 2: n space-separated integers
Line 3: target number

Output Format:
Index of element or -1 if not found

Sample Input:
7
4 5 6 7 0 1 2
6

Sample Output:
2


"
*/


#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] == x) return m;
        if (arr[l] <= arr[m]) {
            if (x >= arr[l] && x < arr[m]) r = m - 1;
            else l = m + 1;
        } else {
            if (x > arr[m] && x <= arr[r]) l = m + 1;
            else r = m - 1;
        }
    }
    return -1;
}

int main() {
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    cout << search(arr, x) << endl;
    return 0;
}