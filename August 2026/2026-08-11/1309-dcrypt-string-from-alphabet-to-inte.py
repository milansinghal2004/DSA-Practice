# 1309 leetcode decrypt-string-from-alphabet-to-integer-mapping;string;help

class Solution(object):
    def freqAlphabets(self, s):
        """
        :type s: str
        :rtype: str
        """
        ans = ""
        i = 0
        n = len(s)

        while i < n:

            # Two-digit number followed by '#'
            if i + 2 < n and s[i + 2] == '#':
                val = int(s[i:i + 2])
                ans += chr(ord('a') + val - 1)
                i += 3

            # Single digit
            else:
                val = int(s[i])
                ans += chr(ord('a') + val - 1)
                i += 1

        return ans    
