// 37-sudoku-solver.cpp;array-matrix;help;leetcode

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '1';
                    row[r][num] = col[c][num] = box[(r/3)*3 + c/3][num] = true;
                }
            }
        }

        function<bool(int,int)> dfs = [&](int r, int c) -> bool {
            if (r == 9) return true;
            int nextR = (c == 8) ? r + 1 : r;
            int nextC = (c + 1) % 9;
            if (board[r][c] != '.') return dfs(nextR, nextC);
            for (int num = 0; num < 9; num++) {
                int boxIdx = (r/3)*3 + c/3;
                if (!row[r][num] && !col[c][num] && !box[boxIdx][num]) {
                    board[r][c] = '1' + num;
                    row[r][num] = col[c][num] = box[boxIdx][num] = true;
                    if (dfs(nextR, nextC)) return true;
                    board[r][c] = '.';
                    row[r][num] = col[c][num] = box[boxIdx][num] = false;
                }
            }
            return false;
        };
        dfs(0,0);
    }
};