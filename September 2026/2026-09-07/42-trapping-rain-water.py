42-trapping-rain-water.cpp;stack-2p;self;leetcode

class Solution:
    def trap(self, height: List[int]) -> int:
        start = 0
        end = len(height) - 1
        leftM = 0
        rightM = 0
        totalM = 0

        while start <= end:
            leftM = max(leftM, height[start])
            rightM = max(rightM, height[end])

            if leftM < rightM:
                totalM += leftM - height[start]
                start += 1
            else:
                totalM += rightM - height[end]
                end -= 1

        return totalM