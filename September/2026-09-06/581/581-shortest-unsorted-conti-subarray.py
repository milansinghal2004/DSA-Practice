# 581-shortest-unsorted-conti-subarray.cpp;2p;self;leetcode

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        left = 0
        while left < n - 1 and nums[left] <= nums[left + 1]:
            left += 1

        if left == n - 1:
            return 0

        right = n - 1
        while right > 0 and nums[right - 1] <= nums[right]:
            right -= 1

        sub_min = min(nums[left:right + 1])
        sub_max = max(nums[left:right + 1])

        while left > 0 and nums[left - 1] > sub_min:
            left -= 1

        while right < n - 1 and nums[right + 1] < sub_max:
            right += 1

        return right - left + 1