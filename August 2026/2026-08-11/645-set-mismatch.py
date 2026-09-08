# 645 leetcode set-mismatch.py;array;syntax-help

class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        duplicate = -1
        missing = -1

        for i in range(1, n + 1):
            count = 0

            for num in nums:
                if num == i:
                    count += 1

            if count == 2:
                duplicate = i

            if count == 0:
                missing = i        

        return [duplicate, missing]