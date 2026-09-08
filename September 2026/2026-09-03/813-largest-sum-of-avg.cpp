// 813-largest-sum-of-avg.cpp;prefixsum;help;leetcode

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<double> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = prefix[i] / i;
        }

        for (int groups = 2; groups <= k; groups++) {

            vector<double> newDp(n + 1, 0);
            for (int i = groups; i <= n; i++) {
                for (int j = groups - 1; j < i; j++) {
                    double average = (prefix[i] - prefix[j]) / (i - j);

                    newDp[i] = max(newDp[i],dp[j] + average);
                }
            }

            dp = newDp;
        }

        return dp[n];
    }
};