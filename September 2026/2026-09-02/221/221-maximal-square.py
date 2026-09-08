# 221-maximal-square.py;array;syntax-help;leetcode
# https://leetcode.com/problems/maximal-square/

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        row = len(matrix)
        col = len(matrix[0])

        dp = [[0] * col for _ in range(row)]

        maxS = 0

        for i in range(row):
            for j in range(col):
                if matrix[i][j] == '1':
                    if i == 0 or j == 0:
                        dp[i][j] = 1

                    else:
                        dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])

                    maxS = max(maxS, dp[i][j])

        return maxS * maxS