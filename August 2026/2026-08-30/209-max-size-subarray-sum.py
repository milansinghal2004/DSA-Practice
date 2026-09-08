# 209-max-size-subarray-sum.py;prefix-sum;leetcode

class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        current_sum = 0
        min_length = float("inf")

        for right in range(len(nums)):
            current_sum += nums[right]

            # Shrink the window while its sum meets the target
            while current_sum >= target:
                min_length = min(min_length, right - left + 1)
                current_sum -= nums[left]
                left += 1

        return 0 if min_length == float("inf") else min_length