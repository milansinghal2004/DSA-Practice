# 661-img-smoother.py;matrix;leetcode

class Solution(object):
    def imageSmoother(self, img):
        """
        :type img: List[List[int]]
        :rtype: List[List[int]]
        """
        rows = len(img)
        cols = len(img[0])
        result = [[0] * cols for _ in range(rows)]

        for r in range(rows):
            for c in range(cols):
                total = 0
                count = 0

                for dr in range(-1, 2):
                    for dc in range(-1, 2):
                        nr = r + dr
                        nc = c + dc

                        if 0 <= nr < rows and 0 <= nc < cols:
                            total += img[nr][nc]
                            count += 1

                result[r][c] = total // count

        return result