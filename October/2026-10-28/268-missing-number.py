# 268-missing-number.py;leetcode;math;help

class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        n = len(nums)
        actual = 0
        left = n * (n + 1) // 2

        for i in range(len(nums)):
            actual += nums[i]

        return left - actual