# 1089-duplicate-zeroes.py;math;leetcpde

class Solution:
    def duplicateZeros(self, arr: list[int]) -> None:
        n = len(arr)
        i = 0

        while i < n:
            if arr[i] == 0:
                arr.insert(i + 1, 0)
                arr.pop()
                i += 1
            i += 1