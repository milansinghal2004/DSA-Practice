# 396-rotate-function.cpp;dp;help;leetcode

class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        n = len(nums)
        total_sum = sum(nums)
        prev = sum(nums[i] * i for i in range(n))
        ans = prev
        index = n - 1

        for _ in range(1, n):
            prev = prev + total_sum - n * nums[index]

            index -= 1

            ans = max(ans, prev)

        return ans