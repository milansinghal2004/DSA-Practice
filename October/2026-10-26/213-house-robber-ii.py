# 213-house-robber-ii.py;math;leetcode

class Solution:
    def solve(self, nums: list[int], start: int, end: int) -> int:
        prev2 = 0
        prev1 = 0

        for i in range(start, end + 1):
            current = max(prev1, prev2 + nums[i])

            prev2 = prev1
            prev1 = current

        return prev1

    def rob(self, nums: list[int]) -> int:
        n = len(nums)

        if n == 1:
            return nums[0]

        case1 = self.solve(nums, 1, n - 1)
        case2 = self.solve(nums, 0, n - 2)

        return max(case1, case2)
