# 43-multiply-string.cpp;maths-string;help;leetcode

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        m = len(num1)
        n = len(num2)

        result = [0] * (m + n)

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                a = ord(num1[i]) - ord('0')
                b = ord(num2[i]) - ord('0')

                product = a * b
                pos1 = i + j
                pos2 = i + j + 1
                total = product + result[pos2]

                result[pos2] = total % 10
                result[pos1] += total // 10

        i = 0
        while i < len(result) and result[i] == 0:
            i += 1

        ans = ""

        while i < len(result):
            ans += chr(result[i] + ord('0'))
            i += 1

        return ans