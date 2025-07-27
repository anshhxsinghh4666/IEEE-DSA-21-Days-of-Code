/*
"Count Occurrences using Binary Search
Problem Statement:
Write a program to count how many times a number occurs in a sorted array using binary search.

Description:
Use binary search to find the first and last occurrence, and calculate the count from those indices.

Input Format:
Line 1: n (size of array)
Line 2: n space-separated sorted integers
Line 3: target integer

Output Format:
Count of occurrences of the target integer

Sample Input:
7
1 2 2 2 3 4 5
2

Sample Output:
3


"*/


#include <iostream>
#include <vector>

using namespace std;

int first(const vector<int>& a, int x) {
    int l = 0, r = a.size() - 1, res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) { res = m; r = m - 1; }
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return res;
}

int last(const vector<int>& a, int x) {
    int l = 0, r = a.size() - 1, res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) { res = m; l = m + 1; }
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return res;
}

int main() {
    int n, x;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;
    
    int f = first(a, x), l = last(a, x);
    if (f == -1) cout << 0 << endl;
    else cout << (l - f + 1) << endl;
    
    return 0;
}