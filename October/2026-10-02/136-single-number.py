# 136-single-number.py;math-bit-maniplation.cpp;help;leetcode

class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        ans = 0

        for i in range(32):
            count = 0

            for num in nums:
                if (num >> i) & 1:
                    count += 1

            if count % 3 != 0:
                ans |= (1 << i)

        if ans >= 2**31:
            ans -= 2**32

        return ans