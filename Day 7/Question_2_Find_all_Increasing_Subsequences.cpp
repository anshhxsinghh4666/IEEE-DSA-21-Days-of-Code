/*
"Find All Increasing Subsequences (Length ≥ 2)
Problem Statement:
Write a program to find all increasing subsequences (of length ≥ 2) in an array.

Description:
Use backtracking to generate all valid increasing subsequences.

Input Format:
An integer n
n space-separated integers

Output Format:
Each subsequence on a new line

Sample Input:
4
4 6 7 7

Sample Output:
7 7
6 7
4 6
4 6 7 7
4 7 7
4 6 7
4 7
6 7 7


"
*/


#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> result;

void dfs(vector<int>& nums, int index, vector<int>& path) {
    if (path.size() >= 2) {
        result.insert(path);
    }
    
    for (int i = index; i < nums.size(); i++) {
        if (path.size() == 0 || nums[i] >= path.back()) {
            path.push_back(nums[i]);
            dfs(nums, i + 1, path);
            path.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<int> path;
    dfs(nums, 0, path);
    
    for (const auto& seq : result) {
        for (int i = 0; i < seq.size(); i++) {
            cout << seq[i];
            if (i < seq.size() - 1) cout << "" "";
        }
        cout << endl;
    }
    
    return 0;
}