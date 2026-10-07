# 85-max-rectangel.py;array-matrix;help;leetcode

class Solution:
    def maximalRectangle(self, matrix: list[list[str]]) -> int:
        if not matrix:
            return 0

        n = len(matrix)
        m = len(matrix[0])

        count = [0] * m
        maxArea = 0

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == '1':
                    count[j] += 1
                else:
                    count[j] = 0

            for j in range(m):
                if count[j] == 0:
                    continue

                minH = count[j]

                for k in range(j, -1, -1):
                    minH = min(minH, count[k])

                    if minH == 0:
                        break

                    width = j - k + 1
                    maxArea = max(maxArea, minH * width)

        return maxArea