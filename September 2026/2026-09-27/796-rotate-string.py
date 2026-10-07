# 796-rotate-string.py;string;self;leetcode

class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False

        return goal in (s + s)