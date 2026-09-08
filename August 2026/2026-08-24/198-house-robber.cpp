// 198-house-robber.cpp;array;help-syntax;leetcode
// https://leetcode.com/problems/house-robber/?envType=problem-list-v2&envId=array

#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int prev2 = 0;
    int prev1 = 0;

    for (int money : nums) {
        int current = max(prev1, prev2 + money);

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << rob(nums) << endl;

    return 0;
}