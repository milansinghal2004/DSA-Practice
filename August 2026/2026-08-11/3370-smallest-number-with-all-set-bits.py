# 3370 leetcode smallest-number-with-all-set-bits.py;bit-maipulation;help

class Solution(object):
    def smallestNumber(self, n):
        x = 1

        while x < n:
            x = (x << 1) | 1

        return x