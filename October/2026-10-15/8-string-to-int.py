# 8-string-to-int.py;help;leetcode

class Solution:
    def myAtoi(self, s: str) -> int:
        sign = 1
        flag = 0
        ans = 0
        INT_MAX = 2**31 - 1
        INT_MIN = -(2**31)

        for ch in s:
            if ch == ' ' and flag == 0:
                continue

            if ch == '-' and flag == 0:
                flag = 1
                sign = -1
                continue

            if ch == '+' and flag == 0:
                flag = 1
                sign = 1
                continue

            num = ord(ch) - ord('0')

            if 0 <= num <= 9:
                flag = 1
                ans = ans * 10 + num

                if ans > INT_MAX and sign == -1:
                    return INT_MIN
                elif ans > INT_MAX and sign == 1:
                    return INT_MAX
            else:
                break

        return ans * sign
