# 2091-removing-max-and-min-from-array.py;array;alone;leetcode
# https://leetcode.com/problems/removing-minimum-and-maximum-from-array/?envType=daily-question&envId=2026-09-02
class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)

        minI = nums.index(min(nums))
        maxI = nums.index(max(nums))

        left = min(minI, maxI)
        right = max(minI, maxI)

        front = right + 1
        back = n - left

        both = (left + 1) + (n - right)

        return min(front, back, both)