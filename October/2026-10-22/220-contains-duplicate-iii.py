# 220-contains-duplicate-iii.py;help;leetcode


class Solution:
    def containsNearbyAlmostDuplicate(self, nums: list[int], indexDiff: int, valueDiff: int) -> bool:
        seen = set(nums)
        n = len(nums)

        if valueDiff == 0 and len(nums) == len(seen):
            return False

        for i in range(n):
            for j in range(i + 1, min(i + indexDiff + 1, n)):
                if abs(nums[i] - nums[j]) <= valueDiff:
                    return True

        return False
