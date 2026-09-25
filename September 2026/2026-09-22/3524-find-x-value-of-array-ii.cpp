// 3524-find-x-value-of-array-ii.cpp;arrayhelp;leetcode

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next(k, 0);
            int x = num % k;
            next[x]++;

            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue;

                int newRemainder = (r * x) % k;

                next[newRemainder] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                result[r] += next[r];
            }

            dp = next;
        }

        return result;
    }
};