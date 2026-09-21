# 3-longest-substring-without-repeating-char.py;sliding-window;help;leetcode

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = 0
        maxL = 0
        j = 0
        mp = {}

        for i in range(len(s)):
            mp[s[i]] = mp.get(s[i], 0) + 1
            length += 1

            while mp[s[i]] > 1:
                mp[s[j]] -= 1
                j += 1
                length -= 1

            maxL = max(maxL, length)
        return maxL