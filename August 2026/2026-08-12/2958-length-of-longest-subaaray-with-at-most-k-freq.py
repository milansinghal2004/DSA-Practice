# 2958-length-of-longest-subaaray-with-at-most-k-freq.py;array;help

class Solution(object):
    def maxSubarrayLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        freq = {}
        left = 0
        maxLen = 0

        for right in range(len(nums)):
            freq[nums[right]] = freq.get(nums[right], 0) + 1

            while freq[nums[right]] > k:
                freq[nums[left]] -= 1
                left += 1

            maxLen = max(maxLen, right - left + 1)

        return maxLen