# 2996 leetcode smallest-missing-integer-greater-than-sequential-prefix-sum.py;array;easy

class Solution(object):
    def missingInteger(self, nums):
        result = nums[0]

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                result += nums[i]
            else:
                break

        s = set(nums)

        while result in s:
            result += 1

        return result