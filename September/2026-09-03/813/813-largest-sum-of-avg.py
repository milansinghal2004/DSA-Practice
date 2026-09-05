# 813-largest-sum-of-avg.py;leetcode;help;sum-prefix

class Solution:
    def largestSumOfAverages(self, nums: List[int], k: int) -> float:
        n = len(nums)
        prefix = [0] * (n + 1)

        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        dp = [0.0] * (n + 1)

        for i in range(1, n + 1):
            dp[i] = prefix[i] / i

        for groups in range(2, k + 1):
            new_dp = [0.0] * (n + 1)

            for i in range(groups, n + 1):
                for j in range(groups - 1, i):
                    average = (prefix[i] - prefix[j]) / (i - j)

                    new_dp[i] = max(
                        new_dp[i],
                        dp[j] + average
                    )

            dp = new_dp

        return dp[n]