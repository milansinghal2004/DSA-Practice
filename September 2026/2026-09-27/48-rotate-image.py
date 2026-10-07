# 48-rotate-image.py;matrix;self;leetcode

class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        n = len(nums)
        dist = [-1] * n
        dist[0] = 0
        for i in range(n):
            if dist[i] == -1: continue
            for j in range( i +  1, n):
                val = nums[j] - nums[i]
                if val >= -target and val <= target:
                    if dist[j] == -1 or dist[j] < dist[i] + 1:
                        dist[j] = dist[i] + 1

        return dist[n - 1]