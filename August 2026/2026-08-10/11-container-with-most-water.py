# 11 leetcode container-with-most-water.py;array-2p;help

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0
        right = len(height) - 1
        maxA = 0

        while left < right:
            h = min(height[left], height[right])
            w = right - left

            maxA = max(maxA, h * w)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        
        return maxA