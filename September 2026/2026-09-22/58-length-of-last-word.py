# 58-length-of-last-word.py;string;self;leetcode

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        length = len(s)
        last = 0

        for i in range(length - 1, -1, -1):
            if s[i] == ' ': continue
            while i >= 0 and s[i] != ' ':
                last += 1
                i -= 1
            
            break
        
        return last