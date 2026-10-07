# 1752-check-if-array-is-sorted-and-rotated.py;array;self;leetcode

class Solution:
    def check(self, nums: list[int]) -> bool:
        count = 0
        n = len(nums)

        for i in range(n):
            if nums[i] > nums[(i + 1) % n]:
                count += 1

            if count > 1:
                return False

        return True