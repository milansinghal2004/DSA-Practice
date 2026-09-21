# 38-count-nd-say.py;string;helpleetcode

class Solution:
    def countAndSay(self, n: int) -> str:
        s = "1"
        for _ in range(1, n):
            next_s = ""
            i = 0

            while i < len(s):
                j = i
                while j < len(s) and s[j] == s[i]:
                    j += 1

                count = j - i
                next_s += str(count) + s[i]
                i = j

            s = next_s

        return s