// 3665-twisted-mirror-path-count.cpp;math;leetcode;array-dp

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1) return 0;

        vector<int> right(m * n, -1);
        vector<int> down(m * n, -1);

        for (int s = m + n - 2; s >= 0; s--) {
            int start = max(0, s - (n - 1));
            int end = min(m - 1, s);

            for (int i = start; i <= end; i++) {
                int j = s - i;
                int idx = i * n + j;

                if (grid[i][j] == 0) {
                    right[idx] = idx;
                    down[idx] = idx;
                }
                else {
                    if (i + 1 < m) {
                        right[idx] = down[idx + n];
                    }

                    if (j + 1 < n) {
                        down[idx] = right[idx + 1];
                    }
                }
            }
        }

        vector<int> dp(m * n, 0);
        dp[0] = 1;

        for (int s = 0; s < m + n - 1; s++) {
            int start = max(0, s - (n - 1));
            int end = min(m - 1, s);

            for (int i = start; i <= end; i++) {
                int j = s - i;
                int idx = i * n + j;

                if (grid[i][j] == 1 || dp[idx] == 0)
                    continue;

                long long ways = dp[idx];

                if (j + 1 < n) {
                    int dest = right[idx + 1];

                    if (dest != -1) {
                        dp[dest] = (dp[dest] + ways) % MOD;
                    }
                }

                if (i + 1 < m) {
                    int dest = down[idx + n];

                    if (dest != -1) {
                        dp[dest] = (dp[dest] + ways) % MOD;
                    }
                }
            }
        }

        return dp[m * n - 1];
    }
};
