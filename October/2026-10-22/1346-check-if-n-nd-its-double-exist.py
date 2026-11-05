# 1346-check-if-n-nd-its-double-exist.py;math;leetcode;help

class Solution:
    def checkIfExist(self, arr: list[int]) -> bool:
        n = len(arr)

        for i in range(n):
            for j in range(n):
                if i != j and arr[i] == arr[j] * 2:
                    return True

        return False