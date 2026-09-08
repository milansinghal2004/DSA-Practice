# 26-remove-duplicates-from-sorted-array.py;aarray;syntax-help

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mp = {}

        for num in nums:
            mp[num] = mp.get(num, 0) + 1

        k = 0

        for num in sorted(mp):
            nums[k] = num
            k += 1

        return k