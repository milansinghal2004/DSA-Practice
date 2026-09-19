// 363-max-sum-of-rec-no-larger-then-k.cpp;prefix-sum;help;leetcode

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            vector<int> rowSum(m, 0);
            for (int j = i; j < n; j++) {
                for (int row = 0; row < m; row++) {
                    rowSum[row] += matrix[row][j];
                }
                set<int> prefixSums;
                prefixSums.insert(0);

                int prefix = 0;
                for (int row = 0; row < m; row++) {
                    prefix += rowSum[row];
                    auto it = prefixSums.lower_bound(prefix - k);
                    if (it != prefixSums.end()) {
                        ans = max(ans, prefix - *it);
                    }

                    prefixSums.insert(prefix);
                }
            }
        }

        return ans;
    }
};