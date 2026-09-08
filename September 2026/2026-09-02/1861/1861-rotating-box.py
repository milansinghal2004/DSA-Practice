# 1861-rotating-box.py;matrix;help;leetocde
# https://leetcode.com/problems/rotating-the-box/description/

class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        m = len(boxGrid)
        n = len(boxGrid[0])

        for i in range(m):
            empty = n - 1

            for j in range(n - 1, -1, -1):
                if boxGrid[i][j] == '*':
                    empty = j - 1

                elif boxGrid[i][j] == '#':
                    boxGrid[i][j], boxGrid[i][empty] = \
                        boxGrid[i][empty], boxGrid[i][j]
                    empty -= 1

        