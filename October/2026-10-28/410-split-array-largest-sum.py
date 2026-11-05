# 410-split-array-largest-sum.py;math;leetcode

class Solution:
    def splitArray(self, nums: list[int], k: int) -> int:
        left = max(nums)
        right = sum(nums)

        while left < right:
            mid = (left + right) // 2
            curr = 0
            sub = 1

            for num in nums:
                if curr + num > mid:
                    sub += 1
                    curr = num
                else:
                    curr += num

            if sub > k:
                left = mid + 1
            else:
                right = mid

        return left