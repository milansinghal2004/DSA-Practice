# 168-excel-sheet-col-title.py;math;help;leetcode

class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        ans = ""

        while columnNumber > 0:
            columnNumber -= 1
            ch = chr(ord('A') + (columnNumber % 26))

            ans += ch
            columnNumber //= 26

        ans = ans[::-1]

        return ans