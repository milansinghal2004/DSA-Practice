// 2784-check-if-array-is-good.cpp;array-maths;help;leetcode

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> freq(n + 1, 0);
        for (int x : nums) {
            if (x < 1 || x > n)
                return false;

            freq[x]++;
        }
        for (int x = 1; x < n; x++) {
            if (freq[x] != 1)
                return false;
        }

        return freq[n] == 2;
    }
};