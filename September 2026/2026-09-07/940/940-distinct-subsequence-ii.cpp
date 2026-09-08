// 940-distinct-subsequence-ii.cpp;string-dp;help;leetcode

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(s.size() + 1, 0);
        dp[0] = 1;

        vector<long long> last(26, 0);
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            dp[i + 1] = (2 * dp[i] - last[c] + MOD) % MOD;
            last[c] = dp[i];
        }

        return (dp[s.size()] - 1 + MOD) % MOD;
    }
};