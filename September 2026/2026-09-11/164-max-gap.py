# 164-max-gap.py;array;help;leetcode

class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        n = len(nums)

        if n < 2:
            return 0

        mp = {}

        for i in range(n):
            mp[nums[i]] = 1

        prev = 0
        ans = 0
        check = False

        for key in sorted(mp):
            if check:
                ans = max(ans, key - prev)

            prev = key
            check = True

        return ans