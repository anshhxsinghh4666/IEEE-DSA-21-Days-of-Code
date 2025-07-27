/*
"Problem Statement
You need to develop a program that processes and analyzes large datasets of integers. Your task is to manage data using arrays and pointers and perform operations like sorting, searching, and finding the median.

Requirements
Data Input: There will be an Input of the array of integers dynamically.
Sorting: Sort the array using the quicksort algorithm with pointers.
Searching: Implementing the binary search methodology using pointers to find a specific element.
Median Calculation: Calculate the median of the sorted array using pointers.

Input Format
The first line will contain an integer n, such that 1 <= n <= 100000, representing the number of elements in the array.
The second line contains n space-separated integers representing the array elements.
The third line contains an integer x, representing the element to search in the array.

Output Format
Print the sorted array of integers on a single line, space-separated.
Print the median value of the array on the next line.
Print the result of the binary search on the next line: the index of the element x if found, otherwise -1.

Constraints
All integers are within the range -1000000 to 1000000.
Efficient use of pointers for sorting, searching, and calculating the median.
Consider both odd and even lengths for median calculation.

Example
Input:
7
12 4 5 3 8 7 1
5

Output:
1 3 4 5 7 8 12
5
3

Explanation:
Sorting: The sorted array is [1, 3, 4, 5, 7, 8, 12].
Median: The median value of this sorted array is 5 since it is the middle element.
Binary Search: The element 5 is found at index 3 (0-based index) in the sorted array."

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