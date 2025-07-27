/*
"Merge Overlapping Intervals
Problem Statement:
Write a program to merge all overlapping intervals from a list of intervals.

Description:
Given an array of intervals [start, end], merge the overlapping ones and print the merged intervals sorted by start time.

Input Format:
An integer n
n lines containing two space-separated integers

Output Format:
Merged intervals, one per line

Sample Input:
4
1 3
2 6
8 10
15 18

Sample Output:
1 6
8 10
15 18

"
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> intervals(n);
    
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    // Sort intervals by start time
    sort(intervals.begin(), intervals.end());
    
    vector<pair<int, int>> merged;
    pair<int, int> prev = intervals[0];
    
    for (int i = 1; i < n; i++) {
        pair<int, int> curr = intervals[i];
        if (curr.first <= prev.second) {
            prev.second = max(prev.second, curr.second);
        } else {
            merged.push_back(prev);
            prev = curr;
        }
    }
    
    merged.push_back(prev);
    
    for (const auto& interval : merged) {
        cout << interval.first << "" "" << interval.second << endl;
    }
    
    return 0;