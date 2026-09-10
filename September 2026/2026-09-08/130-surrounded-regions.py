# 130-surrounded-regions;;matrix;self;leetcode

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:
            return 

        row = len(board)
        col = len(board[0])

        for i in range(row):
            self.check(board, i, 0, row, col)

            if col > 1:
                self.check(board, i, col - 1, row, col)

        for j in range(1, col - 1):
            self.check(board, 0, j, row, col)

            if col > 1:
                self.check(board, row - 1, j, row, col)

        for i in range(row):
            for j in range(col):
                if board[i][j] == 'O':
                    board[i][j] = 'X'

        for i in range(row):
            for j in range(col):
                if board[i][j] == '1':
                    board[i][j] = 'O'

    def check(self, board, i, j, row, col):
        if board[i][j] == 'O':
            board[i][j] = '1'

            if i > 0:
                self.check(board, i - 1, j, row, col)

            if j > 0:
                self.check(board, i, j - 1, row, col)

            if i + 1 < row:
                self.check(board, i + 1, j, row, col)

            if j + 1 < col:
                self.check(board, i, j + 1, row, col)