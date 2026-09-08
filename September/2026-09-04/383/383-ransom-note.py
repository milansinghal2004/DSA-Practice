# 383-ransom-note.cpp;string;self;leetcode

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mp = {}

        for ch in magazine:
            if ch in mp:
                mp[ch] += 1
            else:
                mp[ch] = 1

        for ch in ransomNote:
            if ch not in mp or mp[ch] == 0:
                return False

            mp[ch] -= 1

        return True