# 2553-seprate-digits-in-array.py;math;help;leetcode
class Solution:
    def separateDigits(self, nums: list[int]) -> list[int]:
        n = len(nums)
        ans = []

        for i in range(n):
            num = nums[i]
            digit = []
            while num:
                digit.append(num % 10)
                num //= 10
            digit.reverse()
            ans.extend(digit)

        return ans