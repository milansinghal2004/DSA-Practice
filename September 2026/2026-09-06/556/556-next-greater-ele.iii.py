# 556-next-greater-ele.iii.cpp;2p;help;leetcode

class Solution:
    def nextGreaterElement(self, n: int) -> int:
        num = list(str(n))
        i = len(num) - 2

        while i >= 0 and num[i] >= num[i + 1]:
            i -= 1

        if i < 0:
            return -1

        j = len(num) - 1

        while j >= 0 and num[j] <= num[i]:
            j -= 1

        num[i], num[j] = num[j], num[i]
        num[i + 1:] = reversed(num[i + 1:])

        result = int(''.join(num))
        if result > 2**31 - 1:
            return -1

        return result