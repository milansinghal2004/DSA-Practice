# 1010-pairs-of-songs-with-total-duration-divisible-by-60.py;array;help-syntax;leetcode

class Solution:
    def numPairsDivisibleBy60(self, time: list[int]) -> int:
        freq = [0] * 60
        ans = 0
        for i in time:
            remainder = i % 60
            required = (60 - remainder) % 60
            ans += freq[required]
            freq[remainder] += 1

        return ans