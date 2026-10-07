# 81-search-in-rotated-sorted-array-ii.py;self;array;leetcopde

class Solution:
    def search(self, nums: list[int], target: int) -> bool:
        for i in range(len(nums)):
            if target == nums[i]: return True

        return False