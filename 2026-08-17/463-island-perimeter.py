# 463-island-perimeter.py;array;help;leetcode

class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        perimeter = 0
        rows = len(grid)
        cols = len(grid[0])

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    perimeter += 4

                    if c > 0 and grid[r][c - 1] == 1:
                        perimeter -= 2

                    if r > 0 and grid[r - 1][c] == 1:
                        perimeter -= 2

        return perimeter