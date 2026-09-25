# 53-max-subarray.py;array;help;leetcode

class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        sum = nums[0]
        m_sum = nums[0]

        for i in range(1, len(nums)):
            sum = max(nums[i], nums[i] + sum)
            m_sum = max(m_sum, sum)

        return m_sum