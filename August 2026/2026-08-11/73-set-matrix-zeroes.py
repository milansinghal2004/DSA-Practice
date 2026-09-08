# 73 leetcode set-matrix-zeroes.py;array;syntax-help

class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        rowZero = False
        colZero = False

        for i in range(m):
            if matrix[i][0] == 0: colZero = True
        
        for j in range(n):
            if matrix[0][j] == 0: rowZero = True

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        for i in range(1, m):
            if matrix[i][0] == 0:
                for j in range(1, n):
                    matrix[i][j] = 0

        for j in range(1, n):
            if matrix[0][j] == 0:
                for i in range(1, m):
                    matrix[i][j] = 0

        if rowZero:
            for j in range(n):
                matrix[0][j] = 0

        if colZero:
            for i in range(m):
                matrix[i][0] = 0

        