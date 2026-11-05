# 455-assign-cookies.py;self;leetcode;sorting-math

class Solution:
    def findContentChildren(self, g: list[int], s: list[int]) -> int:
        g.sort()
        s.sort()

        child = 0
        cookie = 0
        count = 0

        while child < len(g) and cookie < len(s):
            if s[cookie] >= g[child]:
                count += 1
                child += 1
                cookie += 1
            else:
                cookie += 1

        return count