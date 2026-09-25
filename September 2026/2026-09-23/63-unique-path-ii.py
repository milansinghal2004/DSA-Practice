# 62-unique-path-ii.py;help;leetcode

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: list[list[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        way = [[0] * n for _ in range(m)]

        if obstacleGrid[0][0] == 1:
            return 0

        way[0][0] = 1
        for i in range(m):
            for j in range(n):

                if obstacleGrid[i][j] == 1:
                    way[i][j] = 0

                elif i == 0 and j == 0:
                    continue

                else:
                    if i > 0:
                        way[i][j] += way[i - 1][j]

                    if j > 0:
                        way[i][j] += way[i][j - 1]

        return way[m - 1][n - 1]