# 217-contains-duplicate.py;array-sorting;self;leeetcode

class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        nums.sort()

        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                return True

        return False