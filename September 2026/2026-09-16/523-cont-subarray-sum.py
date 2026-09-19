# 523-cont-subarray-sum.cpp;prefixsum;help;leetcode

class Solution:
    def checkSubarraySum(self, nums: list[int], k: int) -> bool:
        mp = {0: -1}
        prefix_sum = 0

        for i in range(len(nums)):
            prefix_sum += nums[i]

            rem = prefix_sum % k

            if rem in mp:
                if i - mp[rem] >= 2:
                    return True
            else:
                mp[rem] = i

        return False