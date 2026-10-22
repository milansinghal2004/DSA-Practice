# 414-third-max-number.py;self;leetcode 

class Solution:
    def thirdMax(self, nums: list[int]) -> int:
        first = second = third = float('-inf')

        for num in nums:
            # Ignore duplicates
            if num == first or num == second or num == third:
                continue

            if num > first:
                third = second
                second = first
                first = num
            elif num > second:
                third = second
                second = num
            elif num > third:
                third = num

        if third == float('-inf'):
            return first

        return int(third)
