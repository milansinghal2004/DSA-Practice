// 322-coin-change.cpp.;dp;help;'leetocde


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    if (dp[i - coin] + 1 < dp[i]) {
                        dp[i] = dp[i - coin] + 1;
                    }
                }
                else {
                    dp[i] = dp[i];
                }
            }
        }

        if (dp[amount] > amount) {
            return -1;
        }
        else {
            return dp[amount];
        }
    }
};