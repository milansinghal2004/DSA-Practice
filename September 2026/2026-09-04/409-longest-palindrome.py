# 409-longest-palindrome.cpp;help-syntax;map;leetcode

class Solution:
    def longestPalindrome(self, s: str) -> int:
        mp = {}

        for ch in s:
            mp[ch] = mp.get(ch, 0) + 1

        length = 0
        hasOdd = False

        for count in mp.values():
            length += (count // 2) * 2

            if count % 2 == 1:
                hasOdd = True

        if hasOdd:
            length += 1

        return length