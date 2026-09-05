# 3876-construct-unifor-parity-ii.py;leetcode

class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        min_odd = float('inf')
        has_even = False

        for x in nums1:
            if x % 2 == 1:
                min_odd = min(min_odd, x)
            else:
                has_even = True

        if not has_even or min_odd == float('inf'):
            return True

        for x in nums1:
            if x % 2 == 0 and x <= min_odd:
                return False

        return True