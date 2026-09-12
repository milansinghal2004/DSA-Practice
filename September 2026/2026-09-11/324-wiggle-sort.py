# 324-wiggle-sort-ii.py;self;array;leetcode

class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        temp = nums.copy()
        temp.sort()

        n = len(nums)

        left = (n - 1) // 2
        right = n - 1

        for i in range(n):
            if i % 2 == 0:
                nums[i] = temp[left]
                left -= 1
            else:
                nums[i] = temp[right]
                right -= 1