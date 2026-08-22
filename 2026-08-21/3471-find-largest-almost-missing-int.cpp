// 3471-find-largest-almost-missing-int.cpp;array;help;leetcode

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int largestAlmostMissing(vector<int>& nums, int k) {
    unordered_map<int, int> count;

    for (int i = 0; i <= nums.size() - k; i++) {

        unordered_set<int> seen;

        for (int j = i; j < i + k; j++) {
            seen.insert(nums[j]);
        }

        for (int x : seen) {
            count[x]++;
        }
    }

    int ans = -1;

    for (auto it : count) {

        if (it.second == 1) {
            ans = max(ans, it.first);
        }
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << largestAlmostMissing(nums, k);

    return 0;
}