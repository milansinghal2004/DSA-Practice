# 3731-find-missing-elements.py;array;help

class Solution(object):
    def findMissingElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort()
        result = []

        for i in range(len(nums) - 1):
            if nums[i + 1] != nums[i] + 1:
                for x in range(nums[i] + 1, nums[i + 1]):
                    result.append(x)

        return result