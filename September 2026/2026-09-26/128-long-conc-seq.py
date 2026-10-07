# 128-long-conc-seq.py;math;self;leetcode

class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 0: return 0
        if n == 1: return 1

        nums.sort()

        count = 1
        maxM = 1

        for i in range(1, n):
            if nums[i] == nums[i - 1]: continue
            if nums[i] == nums[i - 1] + 1: count += 1
            else: count = 1

            maxM = max(maxM, count)

        return maxM