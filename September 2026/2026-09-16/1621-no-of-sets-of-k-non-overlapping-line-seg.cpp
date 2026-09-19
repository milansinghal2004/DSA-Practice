// 1621-no-of-sets-of-k-non-overlapping-line-seg.cppdp-help;leetcode

class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007;
        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= k; j++) {
            long long sum = 0;
            for (int i = 1; i < n; i++) {
                sum = (sum + dp[i - 1][j - 1]) % MOD;
                dp[i][j] = (dp[i - 1][j] + sum) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};